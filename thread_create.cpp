#include <iostream>
#include <pthread.h>
using namespace std;
void* thread_func(void* arg)
{
    cout << "this is a new thread" << endl;
    return nullptr;
}
void *thread_func2(void* arg)
{
    cout << "this is second thread" << endl;
    return nullptr;
}
int main()
{
    pthread_t ptd1 = 1;
    pthread_t ptd2 = pthread_self();
    cout << ptd1 << " " << ptd2 << endl;
    cout << pthread_equal(ptd1, ptd2) << endl;
    pthread_create(&ptd1, nullptr, thread_func, nullptr);
    pthread_create(&ptd2, nullptr, thread_func2, nullptr);
    pthread_join(ptd1, nullptr);
    pthread_join(ptd2, nullptr);
    return 0;
}