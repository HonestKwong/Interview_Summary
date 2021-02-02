/***********************************************************
  > File Name: sigsfunc.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月02日 星期二 16时45分33秒
    > Modified Time:2021年02月02日 星期二 16时58分34秒
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

void print_set(sigset_t *set) {
    int i;
    for(i = 1; i < 32; i++){
        if(sigismember(set, i))
            putchar('1');
        else
            putchar('0');
    }
    printf("\n");
}

int main(int argc,char* argv[])
{
    sigset_t set, oldset, pedset;
    int ret = 0;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGBUS);
    sigaddset(&set, SIGKILL);

    ret = sigprocmask(SIG_BLOCK, &set, &oldset);
    if(ret == -1) 
        sys_err("sigprocmask error");

    while(1) {
        ret = sigpending(&pedset);
        if(ret == -1) 
            sys_err("sigpending error");

        print_set(&pedset);
        sleep(1);
    }

    return 0;
}

