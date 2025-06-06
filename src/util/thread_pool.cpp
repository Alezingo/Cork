
#include "util/thread_pool.hpp"

std::unique_ptr<ThreadPool> g_threadPool;

ThreadPool& ThreadPool::getPool()
{
    if (!g_threadPool)
    {
        g_threadPool.reset(new ThreadPool());  //	NOLINT
    }

    return (*g_threadPool);
}
