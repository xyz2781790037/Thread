#include "th_pool.hpp"
pool po;
void* task1(void* arg){
    // pthread_t *a = (pthread_t *)arg;
    printf("task1 start\n");
    return nullptr;
}
void *task2(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task2 start\n");
    return nullptr;
}
void *task3(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task3 start\n");
    return nullptr;
}
void *task4(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task4 start\n");
    return nullptr;
}
void *task5(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task5 start\n");
    return nullptr;
}
void *task6(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task6 start\n");
    return nullptr;
}
void *task7(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task7 start\n");
    return nullptr;
}
void *task8(void *arg)
{
    // pthread_t *a = (pthread_t *)arg;
    printf("task8 start\n");
    return nullptr;
}
int main()
{
    po.enqueue(task1);
    po.enqueue(task2);
    po.enqueue(task3);
    po.enqueue(task4);
    po.finish();
    po.enqueue(task5);
    po.enqueue(task6);
    po.enqueue(task7);
    po.enqueue(task8);
    po.finish();
    po.end_thread();
    return 0;
}