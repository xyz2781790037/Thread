#include "threadpool.hpp"
void task1(int num)
{
    std::cout << num << std::endl;
}
void task2(int n,int m)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "hello world" << std::endl;
    }
}
void task3(float num)
{
    if (num > 3.14)
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
}
int main()
{
    pool po(4);
    po.enqueue(task3, 3.55);
    po.enqueue(task3, 3);
    po.enqueue(task1, 2);
    po.enqueue(task2, 1,7);
    return 0;
}