/***********************************************************
  > File Name: pthread_join.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 15时32分46秒
    > Modified Time:2021年02月04日 星期四 16时03分34秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>


struct thrd {
    int var;
    char str[256];
};

/*
void* tfn(void * arg)
{
    struct thrd * tval;
    tval = malloc(sizeof(tval));
    tval->var = 100;
    strcpy(tval->str, "hello thread");
    return (void*)tval;
}

void* tfn(void * arg)
{
    struct thrd  tval;  //局部变量地址, 不可做返回值
    tval.var = 100;
    strcpy(tval.str, "hello thread");
    return (void*)&tval;
}

*/
void* tfn(void * arg)
{
    struct thrd  *tval = (struct thrd*) arg ;  
    tval->var = 100;
    strcpy(tval->str, "hello thread");
    return (void*)&tval;
}

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    pthread_t tid;
    struct thrd* retval;
    struct thrd arg;
    int ret = pthread_create(&tid, NULL, tfn, (void*)&arg);
    if(ret != 0)
        sys_err("pthread_create error");
    
    ret = pthread_join(tid, (void**)&retval);
    if(ret != 0)
        sys_err("pthread_join error");
    //printf("child thread exit with var = %d, str = %s\n", retval->var, retval->str);
    printf("child thread exit with var = %d, str = %s\n", arg.var, arg.str);
    pthread_exit(NULL);

}

