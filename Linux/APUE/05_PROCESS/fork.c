/***********************************************************
  > File Name: fork.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月26日 星期二 21时16分42秒
    > Modified Time:2021年01月26日 星期二 21时27分49秒
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
    printf("before fork-1-\n");
    printf("before fork-2-\n");
    printf("before fork-3-\n");
    printf("before fork-4-\n");

    pid_t pid = fork();
    if(pid < 0) {
        perror("fork error\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("------child is created, pid = %ld, parent-pid:%d\n", getpid(), getppid());
    }
    else if(pid > 0) {
        printf("---parent process: mychild is %ld, my pid: %ld, my parent pid: %ld\n", pid, getpid(), getppid());
    }

    printf("end of file\n");
    return 0;
}

