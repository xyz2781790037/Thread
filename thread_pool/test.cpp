#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>

using namespace std;

queue<void *(*)(void *)> taskQueue; // 任务队列
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int task1_done = 0; // 新增共享状态变量

void *task1(void *arg)
{
    cout << "Task 1 is running" << endl;
    sleep(2);
    cout << "Task 1 is done" << endl;

    return nullptr;
}

void *task2(void *arg)
{

    cout << "Task 2 is running" << endl;
    sleep(2);
    cout << "Task 2 is done" << endl;

    return nullptr;
}
void *task3(void *arg)
{
    cout << "Task 3 is running" << endl;
    sleep(2);
    cout << "Task 3 is done" << endl;
    return nullptr;
}
void executeTasks()
{
    while (!taskQueue.empty())
    {
        void *(*task)(void *) = taskQueue.front();
        taskQueue.pop();

        pthread_t th1;
        pthread_create(&th1, nullptr, task, nullptr);
        pthread_join(th1, nullptr); // 顺序执行每个任务
    }
}

int main()
{
    taskQueue.push(task1);
    taskQueue.push(task2);
    executeTasks();
    taskQueue.push(task3);
    executeTasks();
    vector<vector<int>> v;
    return 0;
}