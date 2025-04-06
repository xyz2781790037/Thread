#include "threadpool.hpp"
int task1(int num)
{
    std::cout << num << std::endl;
    return num;
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
    auto a = po.enqueue(task1, 1);
    // std::cout << a.get() << std::endl;
    po.enqueue(task2, 3, 4);
    po.enqueue(task3, 4);
    po.enqueue(task3, 3.12);
    return 0;
}