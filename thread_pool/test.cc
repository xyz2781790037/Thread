#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <unistd.h>
using namespace std;
pthread_t pth[4];
void *task1(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[0])
    {
        printf("task1 start\n");
    }
    else
    {
        printf("not task1 start ");
        if(*a == pth[1])
        {
            printf("p2\n");
        }
        else if(*a == pth[2])
        {
            printf("p3\n");
        }
        else if(*a == pth[3])
        {
            printf("p4\n");
        }
        else
        {
            printf("p1\n");
        }
    }
    return nullptr;
}
void *task2(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[1])
    {
        printf("task2 start\n");
    }
    else
    {
        printf("not task2 start ");
        if (*a == pth[1])
        {
            printf("p2\n");
        }
        else if (*a == pth[2])
        {
            printf("p3\n");
        }
        else if (*a == pth[3])
        {
            printf("p4\n");
        }
        else
        {
            printf("p1\n");
        }
    }
    return nullptr;
}
void *task3(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[2])
    {
        printf("task3 start\n");
    }
    else
    {
        printf("not task3 start ");
        if (*a == pth[1])
        {
            printf("p2\n");
        }
        else if (*a == pth[2])
        {
            printf("p3\n");
        }
        else if (*a == pth[3])
        {
            printf("p4\n");
        }
        else
        {
            printf("p1\n");
        }
    }
    return nullptr;
}
void *task4(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[3])
    {
        printf("task4 start\n");
    }
    else
    {
        printf("not task4 start ");
        if (*a == pth[1])
        {
            printf("p2\n");
        }
        else if (*a == pth[2])
        {
            printf("p3\n");
        }
        else if (*a == pth[3])
        {
            printf("p4\n");
        }
        else
        {
            printf("p1\n");
        }
    }
    return nullptr;
}
void *task5(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[0])
    {
        printf("task5 start\n");
    }
    else
    {
        printf("not task5 start ");
        if (*a == pth[1])
        {
            printf("p2\n");
        }
        else if (*a == pth[2])
        {
            printf("p3\n");
        }
        else if (*a == pth[3])
        {
            printf("p4\n");
        }
        else
        {
            printf("p1\n");
        }
    }
    return nullptr;
}
void *task6(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[1])
    {
        printf("task6 start\n");
    }
    else
    {
        printf("not task6 start ");
        if (*a == pth[1])
        {
            printf("p2\n");
        }
        else if (*a == pth[2])
        {
            printf("p3\n");
        }
        else if (*a == pth[3])
        {
            printf("p4\n");
        }
        else
        {
            printf("p1\n");
        }
    }
    return nullptr;
}