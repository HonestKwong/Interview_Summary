/***********************************************************
  > File Name: pthread_creat.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 13时29分43秒
    > Modified Time:2021年02月04日 星期四 17时01分46秒
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
        fprintf(stderr, "pthread_create error:%s\n", strerror(ret));
        exit(1);
    }

    ret = pthread_detach(tid);  //设置线程分离 线程终止, 会自动清理pcb, 无需回收
    if (ret != 0) {
        //sys_err("pthread_detach error");
        fprintf(stderr, "pthread_detach error:%s\n", strerror(ret));
        exit(1);
    }

    sleep(1);

    ret = pthread_join(tid, NULL);

    printf("join ret = %d\n", ret);
    if(ret != 0){
        fprintf(stderr, "pthread_join error:%s\n", strerror(ret));
        exit(1);
    }

    printf("main: pid %ld, tid = %lu\n", getpid(), pthread_self());

    pthread_exit((void *)0);
}

