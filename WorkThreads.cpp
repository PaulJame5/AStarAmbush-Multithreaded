#include "WorkThreads.h"

WorkThread::WorkThread()
{
}

WorkThread::~WorkThread()
{
}

ThreadPool WorkThread::systemPool;
ThreadPool WorkThread::subsystemPool;
