/***********************************************************
  > File Name: pthread_shared.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 19时53分18秒
    > Modified Time:2021年02月04日 星期四 22时32分39秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>


pthread_mutex_t mut;  //定义一把互斥锁   可以想象为一个整数

void* tfn(void* arg){
    srand(time(NULL));
    while(1) {
        pthread_mutex_lock(&mut); //加锁   可以想象成 锁--
        printf("hello ");
        sleep(rand() % 3);
        printf("world\n");
        pthread_mutex_unlock(&mut);  //解锁 可以想象为锁++
        sleep(rand() % 3);
    }
    return NULL;
}

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    pthread_t tid;
    srand(time(NULL));
    int ret = pthread_mutex_init(&mut, NULL); //初始化互斥锁   可以认为, 锁的值为1
    if(ret != 0) {
        fprintf(stderr, "pthread_mutex_init error", strerror(ret));
        exit(1);
    }
    srand(time(NULL));

    pthread_create(&tid, NULL, tfn, NULL);

    while(1) {
        pthread_mutex_lock(&mut);
        printf("HELLO ");
        sleep(rand() % 3);
        printf("WORLD\n");
        pthread_mutex_unlock(&mut);
        sleep(rand() % 3);
    }
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mut);   //销毁互斥锁

    return 0;
}

