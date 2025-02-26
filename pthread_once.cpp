#include <iostream>
#include <pthread.h>
using namespace std;

pthread_once_t once_control = PTHREAD_ONCE_INIT;
int global_var = 0;

void init_global_var()
{
    global_var = 42;
}

void *thread_function(void *)
{

    static bool stop = false; // 用于标记是否停止线程池的标志位。 
    pthread_once(&once_control, init_global_var);
    std::cout << "Global variable in thread: " << global_var << std::endl;
    return nullptr;
}

int main() 
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, thread_function, nullptr);
    pthread_create(&thread2, nullptr, thread_function, nullptr);
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    std::cout << "Global variable in main: " << global_var << std::endl;
    return 0;
}
