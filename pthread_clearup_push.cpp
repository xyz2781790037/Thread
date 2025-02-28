#include <iostream>
#include <unistd.h>
#include <pthread.h>
void pthread_cleanup(void *args)
{
    printf("线程清理函数被调用了\n");
}

void *pthread_run(void *args)
{
    pthread_cleanup_push(pthread_cleanup, NULL);

    pthread_exit((void *)1); // 子线程主动退出
    pthread_cleanup_pop(1);  // 这里的参数要为０，否则回调函数会被重复调用
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, pthread_run, NULL);
    sleep(1);

    pthread_join(tid, NULL);
    return 0;
}