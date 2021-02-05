/***********************************************************
  > File Name: pthread_join.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 15时32分46秒
    > Modified Time:2021年02月04日 星期四 15时49分30秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>



void* tfn(void * arg)
{
    return (void*)74;
}

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    pthread_t tid;
    int* retval;
    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if(ret != 0)
        sys_err("pthread_create error");
    
    ret = pthread_join(tid, (void**)&retval);
    if(ret != 0)
        sys_err("pthread_join error");

    printf("child thread exit with %d\n", (int)retval);
    pthread_exit(NULL);


}

