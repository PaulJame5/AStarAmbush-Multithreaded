#pragma once
#ifndef WORK_THREADS_H
#define WORK_THREADS_H
#include "ThreadPool.h"

class WorkThread
{
public:
	WorkThread();
	~WorkThread();
	/// <summary>
	/// Used when it would make sense not to thread each entity
	/// </summary>
	static ThreadPool systemPool;

	/// <summary>
	/// Used when individual calculations are more complicated
	/// </summary>
	static ThreadPool subsystemPool;
};

#endif