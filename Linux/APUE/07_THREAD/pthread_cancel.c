/***********************************************************
  > File Name: pthread_creat.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 13时29分43秒
    > Modified Time:2021年02月04日 星期四 16时19分48秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

void* tfn(void* arg){
    while(1){
    printf("thread: pid %ld, tid = %lu\n", getpid(), pthread_self());
    sleep(1);
    }
    return NULL;
}

int main(int argc,char* argv[])
{
    pthread_t tid;
    pthread_self();

    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create err:%s\n", strerror(errno));
        exit(1);
    }

    printf("main: pid %ld, tid = %lu\n", getpid(), pthread_self());

    sleep(5);
    ret = pthread_cancel(tid);  //终止线程
    if (ret != 0) {
        fprintf(stderr, "pthread_cancel err:%s\n", strerror(errno));
        exit(1);
    }

    while(1);
    //sleep(1);
    //return 0;
    pthread_exit((void *)0);
}

