/***********************************************************
  > File Name: conditionVar_product_consumer.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月05日 星期五 10时15分55秒
    > Modified Time:2021年02月05日 星期五 11时12分14秒
 *******************************************************/

/*借助条件变量模拟 生产者-消费者问题*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

/*链表作为共享数据, 需要被互斥量保护*/

struct msg {
    struct msg* next;
    int num;
};

struct msg* head;

/*静态初始化 一个条件变量 和 一个互斥量*/

pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* consumer(void* p){
    struct msg *mp;
    for(;;){
        pthread_mutex_lock(&lock);   //加锁 互斥量
        while(head == NULL) {
            pthread_cond_wait(&has_product, &lock);    //阻塞等待条件变量, 解锁  pthread_cond_wait返回时, 重写加锁mutex
        }

        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&lock);
        
        printf("-Consumer %lu----%d\n", pthread_self(), mp->num);   //解锁互斥量
        free(mp);
        sleep(rand() % 5);
    }
}

void* producer(void* p)
{
    struct msg* mp;

    for(;;) {
        mp = malloc(sizeof(struct msg));   //加锁
        mp->num = rand() % 1000 +1;
        printf("-Produce ----------------%d\n", mp->num);
        pthread_mutex_lock(&lock);
        mp->next = head;                   //写临界区
        head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);   //唤醒消费者线程
        sleep(rand() % 5);
    }
}
void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    pthread_t pid, cid;
    srand(time(NULL));

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}

