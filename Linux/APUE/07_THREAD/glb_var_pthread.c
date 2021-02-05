/***********************************************************
  > File Name: glb_var_pthread.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 14时30分11秒
    > Modified Time:2021年02月04日 星期四 14时32分30秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>


int var = 100;

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

void* tfn(void* arg) {
    var = 200;
    printf("thread\n");
    return NULL;
}

int main(int argc,char* argv[])
{
    printf("At first var = %d\n", var);
    pthread_t tid;
    pthread_create(&tid, NULL, tfn, NULL);
    sleep(1);

    printf("after pthread_create, var = %d\n", var);

    return 0;
}

