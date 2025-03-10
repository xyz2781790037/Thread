#include "test.cc"
using namespace std;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool runflag = true;
queue<function<void *(void *)>> func;
void enqueue(function<void *(void *)> callback)
{
    pthread_mutex_lock(&mutex);
    func.push(callback);
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}
void end_thread()
{
    pthread_mutex_lock(&mutex);
    runflag = false;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}
void *pool(void *arg)
{
    pthread_mutex_lock(&mutex);
    while (runflag)
    {
        while (func.empty() && runflag)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        if (!runflag)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        auto callback = func.front();
        func.pop();
        pthread_mutex_unlock(&mutex);
        callback(arg);
        pthread_mutex_lock(&mutex);
    }
    pthread_mutex_unlock(&mutex);
    return nullptr;
}
int main()
{
    enqueue(task1);
    enqueue(task2);
    enqueue(task3);
    enqueue(task4);
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&pth[i], nullptr, pool, &pth[i]);
    }
    enqueue(task5);
    enqueue(task6);
    sleep(1);
    end_thread();
    for (int i = 0; i < 4; i++)
    {
        pthread_join(pth[i], nullptr);
    }
    return 0;
}