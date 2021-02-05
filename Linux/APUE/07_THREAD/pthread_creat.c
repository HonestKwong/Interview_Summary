/***********************************************************
  > File Name: pthread_creat.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 13时29分43秒
    > Modified Time:2021年02月04日 星期四 14时46分38秒
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
    pthread_self();

    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if (ret != 0) {
        sys_err("pthread_create error");
    }

    printf("main: pid %ld, tid = %lu\n", getpid(), pthread_self());

    //sleep(1);
    //return 0;
    pthread_exit((void *)0);
}

