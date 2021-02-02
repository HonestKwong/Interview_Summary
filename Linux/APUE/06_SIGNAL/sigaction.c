/***********************************************************
  > File Name: signal.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月02日 星期二 17时06分53秒
    > Modified Time:2021年02月02日 星期二 20时08分52秒
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

void sig_catch(int signo) {    //回调函数, 也就是捕捉函数
    if(signo == SIGINT) {
        printf("catch you!!%d\n", signo);
        sleep(10);
    }
    /*
    else if(signo == SIGQUIT)
        printf("catch quit%d\n", signo);
    */
    return;
}

int main(int argc,char* argv[])
{
    struct sigaction act, oldact;
    act.sa_handler = sig_catch;  //信号捕捉函数
    sigemptyset(&(act.sa_mask)); // 设置信号屏蔽字, 在sig_catch中生效
    sigaddset(&(act.sa_mask), SIGQUIT);
    act.sa_flags = 0;   //经常使用
    int ret = sigaction(SIGINT, &act, &oldact);  //注册信号捕捉函数
    if(ret == -1)
        sys_err("sigaction error");
    //ret = sigaction(SIGQUIT, &act, &oldact);  //注册信号捕捉函数
    //if(ret == -1)
     //   sys_err("sigaction error");

    while(1);

    return 0;
}

