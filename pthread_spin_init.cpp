#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_spinlock_t g_spinlock;

void* thread1_func(void* arg)
{
    FILE* fp = (FILE*)arg;

    // 获取自旋锁
    pthread_spin_lock(&g_spinlock);

    // 进入临界区，访问共享资源
    char* s = "thread1: hello\n";
    fwrite(s, strlen(s), 1, fp);

    // 释放自旋锁
    pthread_spin_unlock(&g_spinlock);
    return NULL;
}

void* thread2_func(void* arg)
{
    FILE* fp = (FILE*)arg;

    // 获取自旋锁
    pthread_spin_lock(&g_spinlock);

    // 进入临界区，访问共享资源
    char* s = "thread2: hello\n";
    fwrite(s, strlen(s), 1, fp);

    // 释放自旋锁
    pthread_spin_unlock(&g_spinlock);
    return NULL;
}

int main()
{
    // 新建文件
    FILE *fp = fopen("pthread_spin_init.txt", "wt");

    // 初始化自旋锁
    pthread_spin_init(&g_spinlock, PTHREAD_PROCESS_PRIVATE);

    // 创建线程
    pthread_t th1;
    pthread_t th2;
    pthread_create(&th1, NULL, thread1_func, fp);
    pthread_create(&th2, NULL, thread2_func, fp);

    // 等待线程结束
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    // 销毁自旋锁
    pthread_spin_destroy(&g_spinlock);

    // 关闭文件
    fclose(fp);
    return 0;
}
