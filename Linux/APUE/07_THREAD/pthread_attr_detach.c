/***********************************************************
  > File Name: pthread_creat.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 13时29分43秒
    > Modified Time:2021年02月04日 星期四 17时46分12秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

void* tfn(void* arg){
    printf("thread: pid %ld, tid = %lu\n", getpid(), pthread_self());
    return NULL;
}

int main(int argc,char* argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    int ret = pthread_attr_init(&attr);
    if(ret != 0){
        fprintf(stderr,"attr_init error:%s\n", strerror(ret));
        exit(1);
    }

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);   //设置线程属性为 分离属性
    if(ret != 0){
        fprintf(stderr,"pthread_attr_setdetachstat error:%s\n", strerror(ret));
        exit(1);
    }

    ret = pthread_create(&tid, &attr, tfn, NULL);
    if (ret != 0) {
        sys_err("pthread_create error");
    }

    ret = pthread_attr_destroy(&attr);
    if(ret != 0){
        fprintf(stderr,"pthread_attr_destroy error:%s\n", strerror(ret));
        exit(1);
    }


    //sleep(1);   //等待


    ret = pthread_join(tid, NULL);
    if(ret != 0){
        fprintf(stderr,"pthread_join error:%s\n", strerror(ret));
        exit(1);

    }

    printf("main: pid %ld, tid = %lu\n", getpid(), pthread_self());
    pthread_exit((void *)0);
}

