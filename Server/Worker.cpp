#include "Worker.h"
#include "ThreadPool.h"

void Worker::operator()()
{
	std::function<void()> task;

	for (;;)
	{
		{
			std::unique_lock<std::mutex> lock(pool.qMutex);

			// Look for task to consume
			while (!pool.poolshutdown.load() && pool.tasks.empty())
			{
				// If the jobs queue is empty, wait for new job
				pool.condition.wait(lock);
			}

			// Terminate all worker threads
			if (pool.poolshutdown)
				return;

			task = pool.tasks.front();
			pool.tasks.pop();
		}
		// Release lock

		// Run Task
		if (task != nullptr)
		{
			task();
		}
	}
}
