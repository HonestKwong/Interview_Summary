/***********************************************************
  > File Name: fork.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月26日 星期二 21时16分42秒
    > Modified Time:2021年01月27日 星期三 19时59分20秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <wait.h>

int main(int argc,char* argv[])
{
    pid_t wpid;
    int i;
    for(i = 0; i < 5; i++){   //这样子会产生2^5-1个进程
        pid_t pid = fork();
        if(pid < 0) {
            perror("fork error\n");
            exit(1);
        }
        else if (pid == 0) {

            printf("------child is created, pid = %ld, parent-pid:%d\n", getpid(), getppid());
            sleep(2);
            break;
        }
        else if(pid > 0) {
            printf("---parent process: mychild is %ld, my pid: %ld, my parent pid: %ld\n", pid, getpid(), getppid());
            //wait(NULL);   //一次wait/waitpid函数调用,只能回收一个子进程
            //wpid = waitpid(-1 , NULL, WNOHANG); //回收任意子进程,没有结束的子进程,父进程直接返回0
            wpid = waitpid(pid, NULL, 0);  //指定一个进程回收
            if (wpid == -1) {
                perror("waitpid");
                exit(1);
            }
            printf("I'm parent, wait a child finish:%d\n", wpid); 
        }
    }

    return 0;
}

