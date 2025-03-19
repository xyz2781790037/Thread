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
void *task8(void* arg)
{
    int *acc = (int *)arg;
    printf("task8 start\n");
    std::cout << *acc << std::endl;
    return nullptr;
}
int main()
{
    int a = 6;
    po.enqueue(task1, nullptr);
    po.enqueue(task2,nullptr);
    po.enqueue(task3,nullptr);
    po.enqueue(task4,nullptr);
    po.enqueue(task5,nullptr);
    po.enqueue(task6,nullptr);
    po.enqueue(task7,nullptr);
    po.enqueue(task8,&a);
    po.finish();
    po.end_thread();
    return 0;
}