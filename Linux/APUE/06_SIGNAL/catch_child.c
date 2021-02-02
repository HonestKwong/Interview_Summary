/***********************************************************
  > File Name: catch_child.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月02日 星期二 20时23分03秒
    > Modified Time:2021年02月02日 星期二 22时40分49秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

void catch_child(int signo){   //有子进程结束, 发送SIGCHLD信号时, 该函数会被内核回调
    pid_t wpid;
    int status;
    //while((wpid = wait(NULL)) != -1) {
    while((wpid = waitpid(-1, &status, 0)) != -1){    //循环回收, 防止僵尸进程出现
        //if(wpid == -1) 
         //   sys_err("wait error");
        if (WIFEXITED(status))
        printf("catch child id %d, ret = %d\n", wpid, WEXITSTATUS(status));
    }

    return;
}

int main(int argc,char* argv[])
{
    pid_t pid;
    //阻塞
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGCHILD);

    sigprocmask(SIG_BLOCK, &set, NULL);

    int i;

    for(i = 0; i < 5; i++){
        if((pid = fork()) == 0)  //创建多个子进程
            break;
    }

    if(i == 5) {
        struct sigaction act;
        act.sa_handler = catch_child;  //设置回调函数
        sigemptyset(&(act.sa_mask));   //设置捕捉函数执行期间屏蔽字
        act.sa_flags = 0; //设置默认属性, 本信号自动屏蔽
        sigaction(SIGCHLD, &act, NULL); //注册信号捕捉函数
        //解除阻塞 (信号) 

        sigprocmask(UNSIG_BLOCK, &set, NULL);
        printf("I'm parent, pid = %d\n", getpid());
        while(1);     //模拟父进程后续逻辑

    }

    else {
        
        printf("I'm child pid = %d\n", getpid());
        return i;
    }
    return 0;
}

