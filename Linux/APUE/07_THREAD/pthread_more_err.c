/***********************************************************
  > File Name: pthread_more.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 14时13分36秒
    > Modified Time:2021年02月04日 星期四 14时24分58秒
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

void* tfn(void* arg) {
    int i = *((int*)arg);
    sleep(i);
    printf("--I'm %dth thread: pid = %d, tid = %lu\n", i+1, getpid(), pthread_self());

    return NULL;
}

int main(int argc,char* argv[])
{
    int i;
    int ret;
    pthread_t tid;
    for(i = 0; i < 5; i++){
        ret = pthread_create(&tid, NULL, tfn, (void*)&i);
        if(ret != 0)
            sys_err("pthread_creat error");
    }
    sleep(i);

    printf("--I'm main: pid = %d, tid = %lu\n", getpid(), pthread_self());

    return 0;
}

