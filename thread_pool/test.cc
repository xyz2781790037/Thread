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
        cout << "task1 start" << endl;
    }
    else
    {
        cout << "not task1 start" << " ";
        if(*a == pth[1])
        {
            cout << "p1" << endl;
        }
        else if(*a == pth[2])
        {
            cout << "p2" << endl;
        }
        else if(*a == pth[3])
        {
            cout << "p3" << endl;
        }
        else
        {
            cout << "p0" << endl;
        }
    }
    return nullptr;
}
void *task2(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[1])
    {
        cout << "task2 start" << endl;
    }
    else
    {
        cout << "not task2 start" << " ";
        if (*a == pth[1])
        {
            cout << "p1" << endl;
        }
        else if (*a == pth[2])
        {
            cout << "p2" << endl;
        }
        else if (*a == pth[3])
        {
            cout << "p3" << endl;
        }
        else
        {
            cout << "p0" << endl;
        }
    }
    return nullptr;
}
void *task3(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[2])
    {
        cout << "task3 start" << endl;
    }
    else
    {
        cout << "not task3 start" << " ";
        if (*a == pth[1])
        {
            cout << "p1" << endl;
        }
        else if (*a == pth[2])
        {
            cout << "p2" << endl;
        }
        else if (*a == pth[3])
        {
            cout << "p3" << endl;
        }
        else
        {
            cout << "p0" << endl;
        }
    }
    return nullptr;
}
void *task4(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[3])
    {
        cout << "task4 start" << endl;
    }
    else
    {
        cout << "not task4 start" << " ";
        if (*a == pth[1])
        {
            cout << "p1" << endl;
        }
        else if (*a == pth[2])
        {
            cout << "p2" << endl;
        }
        else if (*a == pth[3])
        {
            cout << "p3" << endl;
        }
        else
        {
            cout << "p0" << endl;
        }
    }
    return nullptr;
}
void *task5(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[0])
    {
        cout << "task5 start" << endl;
    }
    else
    {
        cout << "not task5 start" << " ";
        if (*a == pth[1])
        {
            cout << "p1" << endl;
        }
        else if (*a == pth[2])
        {
            cout << "p2" << endl;
        }
        else if (*a == pth[3])
        {
            cout << "p3" << endl;
        }
        else
        {
            cout << "p0" << endl;
        }
    }
    return nullptr;
}
void *task6(void *arg)
{
    pthread_t *a = (pthread_t *)arg;
    if (*a == pth[1])
    {
        cout << "task6 start" << endl;
    }
    else
    {
        cout << "not task6 start" << " ";
        if (*a == pth[1])
        {
            cout << "p1" << endl;
        }
        else if (*a == pth[2])
        {
            cout << "p2" << endl;
        }
        else if (*a == pth[3])
        {
            cout << "p3" << endl;
        }
        else
        {
            cout << "p0" << endl;
        }
    }
    return nullptr;
}