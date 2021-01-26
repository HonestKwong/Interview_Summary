/***********************************************************
  > File Name: fork.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月26日 星期二 21时16分42秒
    > Modified Time:2021年01月26日 星期二 21时39分48秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{

    int i;
    for(i = 0; i < 5; i++){   //这样子会产生2^5-1个进程
        pid_t pid = fork();
        if(pid < 0) {
            perror("fork error\n");
            exit(1);
        }
        else if (pid == 0) {
            printf("------child is created, pid = %ld, parent-pid:%d\n", getpid(), getppid());
            break;
        }
        else if(pid > 0) {
            printf("---parent process: mychild is %ld, my pid: %ld, my parent pid: %ld\n", pid, getpid(), getppid());
        }
    }

    return 0;
}

