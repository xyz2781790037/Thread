#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

void *thread_func(void *arg)
{
    int count = 0;
    while (1)
    {
        count++;
    }

    printf("this is a thread cancel test 111\n");
    pthread_testcancel();
    printf("test 222\n");

    printf("Thread cancellation requested. Exiting...\n");
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    usleep(1);
    pthread_cancel(thread);
    printf("call pthread_cancel.\n");
    pthread_join(thread, NULL);
    printf("Thread canceled successfully.\n");
    printf("end\n");
    return 0;
}