#ifndef THREAD_POOL_H
#define THREAD_POOL_H


#include <iostream>
#include <vector>
#include <deque>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool() { setUpWorkerThread(std::thread::hardware_concurrency()); };
    ThreadPool(size_t threads);
    ~ThreadPool();
    void finishExectuion();

    void setUpWorkerThread(size_t threads);
    // Allows us to foraward declare any amount of arguments,( Parameter Packs)
    template<class F, class... Args>

    // We use auto as we do not know et the retun type of the task
    auto addJob(F&& f, Args&&... args)->std::future<typename std::result_of<F(Args...)>::type>;

    void start() { stop = false; }
    unsigned int busy = 0;

private:
    // need to keep track of threads so we can join them later on ending an application
    std::vector< std::thread > workers;

    std::deque< std::function<void()> > tasks;

    std::mutex queue_mutex;
    std::condition_variable cv_finished;
    std::condition_variable cv_task;
    bool stop;

    void consumerThread();
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
{
    setUpWorkerThread(threads);
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::addJob(F&& f, Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared< std::packaged_task<return_type()> >(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if (stop)
        {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }

        tasks.push_back([task]() { (*task)(); });
    }
    cv_task.notify_one();
    return res;
}

inline void ThreadPool::finishExectuion()
{
    std::unique_lock<std::mutex> lock(queue_mutex);
    cv_finished.wait(lock, [this]() { return tasks.empty() && (busy == 0); });
}

inline void ThreadPool::consumerThread()
{
    while (true)
    {

        std::unique_lock<std::mutex> lock(queue_mutex);
        cv_task.wait(lock, [this]() { return stop || !tasks.empty(); });
        if (!tasks.empty())
        {
            // got work. set busy.
            ++busy;

            // pull from task from front of queue
            auto task = tasks.front();
            tasks.pop_front();

            // releases our lock. to run async
            lock.unlock();

            // run function outside context
            task();

            lock.lock();
            --busy;
            cv_finished.notify_one();
        }
        else if (stop)
        {
            break;
        }
    }
}

inline void ThreadPool::setUpWorkerThread(size_t threads)
{
    for (unsigned int i = 0; i < threads; ++i)
        workers.emplace_back(std::bind(&ThreadPool::consumerThread, this));
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
}

#endif