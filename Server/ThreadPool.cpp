#include "ThreadPool.h"
#include "Worker.h"
#include <iostream>

ThreadPool::ThreadPool(size_t num_threads) : poolshutdown(false)
{
	workerThreads.reserve(num_threads * sizeof(Worker));
	for (size_t i = 0; i < num_threads; ++i)
	{
		workerThreads.push_back(std::thread(Worker(*this)));
	}
}

ThreadPool::~ThreadPool()
{
	// Withhold all threads
	poolshutdown.store(true);
	condition.notify_all();

	// Join all threads with main thread
	for (auto& wthread : workerThreads)
	{
		wthread.join();
	}
}

void ThreadPool::AddToQueue(std::function<void()> fn)
{
	{
		// Create lock and lock
		std::unique_lock<std::mutex> lck(qMutex);
		// Add new job
		tasks.push(std::move(fn));
	}// Unlock

	// Ask one thread to wake up and do work
	condition.notify_one();
}