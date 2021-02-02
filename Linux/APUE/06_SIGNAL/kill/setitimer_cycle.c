/***********************************************************
  > File Name: setitimer_cycle.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月31日 星期日 21时30分06秒
    > Modified Time:2021年01月31日 星期日 22时06分37秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
#include <signal.h>

void myfunc(int signo) 
{
    printf("hello world\n");
}


void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    struct itimerval it, oldit;

    signal(SIGALRM, myfunc);

    it.it_value.tv_sec = 2;
    it.it_value.tv_usec = 0;

    it.it_interval.tv_sec = 5;
    it.it_interval.tv_usec = 0;

    if(setitimer(ITIMER_REAL, &it, &oldit) == -1)
        sys_err("setitimer error");
    
    while(1);

    return 0;
}

