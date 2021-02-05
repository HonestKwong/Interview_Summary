/***********************************************************
  > File Name: sem_product_consumer.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月05日 星期五 12时07分10秒
    > Modified Time:2021年02月05日 星期五 16时24分23秒
 *******************************************************/
/* 信号量实现 生产者 消费者问题*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>

#define NUM 5
int queue[NUM];
sem_t blank_number, product_number; 

void* producer(void* arg){
    int i = 0;
    while(1) {
        sem_wait(&blank_number);      //生产者将空格数--, 为0 则阻塞等待
        queue[i] = rand() % 1000 + 1; // 生产一个产品
        printf("----Produce----%d\n", queue[i]);
        sem_post(&product_number);   //将产品数++

        i = (i+1) % NUM;          //借助下标实现环形
        sleep(rand() % 1);
    }
}


void* consumer(void* arg)
{
    int i = 0;
    while(1) {
    sem_wait(&product_number);
    printf("-Consume---%d\n", queue[i]);   //消费者将产品数--, 为0 则阻塞等待
    queue[i] = 0;//消费一个产品
    sem_post(&blank_number);     //消费掉以后, 将空格子数++

    i = (i+1) % NUM;
    sleep(rand() % 3);
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
    sem_init(&blank_number, 0, NUM);
    sem_init(&product_number, 0, 0);

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    sem_destroy(&blank_number);
    sem_destroy(&product_number);

    return 0;
}

