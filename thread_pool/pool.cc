#include "test.cc"
using namespace std;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool runflag = true;
queue<function<void *(void *)>> func;
void *pool(void *arg)
{
    pthread_mutex_lock(&mutex);
    while (runflag || !func.empty())
    { // 处理剩余任务
        while (func.empty() && runflag)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        if (!func.empty())
        {
            auto callback = func.front();
            func.pop();
            pthread_mutex_unlock(&mutex);
            callback(arg);
            pthread_mutex_lock(&mutex);
        }
    }
    pthread_mutex_unlock(&mutex);
    return nullptr;
}
void enqueue(function<void *(void *)> callback)
{
    pthread_mutex_lock(&mutex);
    func.push(callback);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}
// 安全终止函数
void end_thread()
{
    pthread_mutex_lock(&mutex);
    runflag = false;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}

// 主函数改进
int main()
{
    enqueue(task1);
    enqueue(task2);
    enqueue(task3);
    enqueue(task4);
    // enqueue(task5);
    // enqueue(task6);
    for (int i = 0; i < 4; i++)
    {
        pthread_create(&pth[i], nullptr, pool, &pth[i]);
    }
    enqueue(task5);
    enqueue(task6);

    // 等待所有任务完成
    pthread_mutex_lock(&mutex);
    while (!func.empty())
    {
        pthread_mutex_unlock(&mutex);
        sleep(1);
        pthread_mutex_lock(&mutex);
    }
    pthread_mutex_unlock(&mutex);

    end_thread();
    for (int i = 0; i < 4; i++)
    {
        pthread_join(pth[i], nullptr);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}