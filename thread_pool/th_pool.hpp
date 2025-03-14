#include <iostream>
#include <unistd.h>
#include <iostream>
#include <queue>
#include <functional>
#include <pthread.h>
#include <vector>
class pool
{
private:
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    void *(*callback)(void *);
    bool runflag = true;

public:
    std::queue<std::function<void *(void *)>> works;
    std::vector<pthread_t> pth;
    int thread_count;

public:
    pool(int n = 4)
    {
        pthread_cond_init(&cond, nullptr);
        pthread_mutex_init(&mutex, nullptr);
        this->thread_count = n;
        pth.resize(n);
        for (int i = 0; i < n; i++)
        {
            pthread_create(&pth[i], nullptr, &pool::staticTask, this);
        }
    }
    ~pool()
    {
        for (int i = 0; i < thread_count; i++)
        {
            pthread_join(pth[i], nullptr);
        }
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&cond);
    }
    static void *staticTask(void *arg)
    {
        pool *self = static_cast<pool *>(arg);
        return self->task(arg); // 调用实际的任务处理函数
    }
    void* task(void* arg){
        pthread_mutex_lock(&mutex);
        while (runflag || !works.empty())
        {
            while (works.empty() && runflag)
            {
                pthread_cond_wait(&cond, &mutex);
            }
            if (!works.empty())
            {
                auto callback = works.front();
                works.pop();
                pthread_mutex_unlock(&mutex);
                callback(arg);
                pthread_mutex_lock(&mutex);
            }
        }
        pthread_mutex_unlock(&mutex);
        return nullptr;
    }
    void enqueue(std::function<void *(void *)> callback)
    {
        pthread_mutex_lock(&mutex);
        works.push(callback);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    void end_thread()
    {
        pthread_mutex_lock(&mutex);
        runflag = false;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    void finish()
    {
        pthread_mutex_lock(&mutex);
        while (!works.empty())
        {
            pthread_mutex_unlock(&mutex);
            sleep(1);
            pthread_mutex_lock(&mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
};