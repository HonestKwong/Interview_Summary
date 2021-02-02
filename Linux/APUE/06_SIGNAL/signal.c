/***********************************************************
  > File Name: signal.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月02日 星期二 17时06分53秒
    > Modified Time:2021年02月02日 星期二 17时29分19秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

void sig_catch(int signo) {
    printf("catch you!!%d\n", signo);
    //printf("");
    return;
}

int main(int argc,char* argv[])
{
    signal(SIGINT, sig_catch);

    while(1);

    return 0;
}

