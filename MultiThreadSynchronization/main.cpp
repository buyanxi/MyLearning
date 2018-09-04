#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

#define MAX 10

pthread_t         g_sThread[2];
pthread_mutex_t   g_sMutex;
int               g_iNumber=0, i;

void *thread1(void *arg1)
{
    //printf ("thread1 : I'm thread 1\n");
    for (i = 0; i < MAX; i++)
    {
        printf("thread1 : number = %d\n", g_iNumber);
        pthread_mutex_lock(&g_sMutex);
        g_iNumber++;
        pthread_mutex_unlock(&g_sMutex);
        sleep(1);
    }
    printf("thread1 :主函数在等我完成任务吗？\n");
    pthread_exit(NULL);
}

void *thread2(void *arg2)
{
    //printf("thread2 : I'm thread 2\n");
    for (i = 0; i < MAX; i++)
    {
        printf("thread2 : number = %d\n", g_iNumber);
        pthread_mutex_lock(&g_sMutex);
        g_iNumber++;
        pthread_mutex_unlock(&g_sMutex);
        sleep(2);
    }
    printf("thread2 :主函数在等我完成任务吗？\n");
    pthread_exit(NULL);
}

void thread_create()
{
    int temp;
    memset(&g_sThread, 0, sizeof(g_sThread));
    /*创建线程*/
    if((temp = pthread_create(&g_sThread[0], NULL, thread1, NULL)) != 0)
        printf("线程1创建失败!\n");
    else
        printf("线程1被创建\n");

    if((temp = pthread_create(&g_sThread[1], NULL, thread2, NULL)) != 0)
        printf("线程2创建失败");
    else
        printf("线程2被创建\n");
}

void thread_wait(void)
{
    /*等待线程结束*/
    if(g_sThread[0] !=0) {
        pthread_join(g_sThread[0],NULL);
        printf("线程1已经结束\n");
    }
    if(g_sThread[1] !=0) {
        pthread_join(g_sThread[1],NULL);
        printf("线程2已经结束\n");
   }
}

int main()
{
    /*用默认属性初始化互斥锁*/
    pthread_mutex_init(&g_sMutex, NULL);

    printf("我是主函数哦，我正在创建线程，呵呵\n");
    thread_create();
    printf("我是主函数哦，我正在等待线程完成任务阿，呵呵\n");
    thread_wait();
    return 0;
}
