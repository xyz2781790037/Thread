#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <unistd.h>
using namespace std;
void *(*callback)(void *);
class pool
{
public:
    queue<function<void *(void *)>> func;
    pool()
    {
        pthread_t pth[4];
        
        for (int i = 0; i < 4; i++)
        {
            callback = func.front().target<void *(void *)>();
            pthread_create(&pth[0], nullptr,callback , nullptr);
            func.pop();
        }
    }
};
void *task1(void *arg)
{
    sleep(2);
    cout << "task1 start" << endl;
    return nullptr;
}
void *task2(void *arg)
{
    cout << "task2 start" << endl;
    return nullptr;
}
void *task3(void *arg)
{
    cout << "task3 start" << endl;
    return nullptr;
}
void *task4(void *arg)
{
    cout << "task4 start" << endl;
    return nullptr;
}
void *task5(void *arg)
{
    cout << "task5 start" << endl;
    return nullptr;
}
void *task6(void *arg)
{
    cout << "task6 start" << endl;
    return nullptr;
}
int main()
{
    queue<function<void *(void *)>> func;
    func.push(task1);
    func.push(task2);
    func.push(task3);
    func.push(task4);
    func.push(task5);
    func.push(task6);
    return 0;
}