#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional> 
#include <vector>
#include <queue>
#include <atomic>

class ThreadPool
{
public:
  ThreadPool(size_t num_threads);
  ~ThreadPool();

  void AddToQueue(std::function<void()> fn);

private:
  friend class Worker;
  std::vector<std::thread> workerThreads;
  std::queue<std::function<void()>> tasks;

  std::mutex qMutex;
  std::condition_variable condition;
  std::atomic<bool> poolshutdown;
};



#endif
