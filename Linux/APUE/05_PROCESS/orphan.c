/***********************************************************
  > File Name: orphan.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月27日 星期三 14时36分31秒
    > Modified Time:2021年01月27日 星期三 14时40分50秒
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
    pid_t pid;
    pid = fork();
    if(pid == 0){
        while(1){
            printf("I am child, myparent pid = %d\n", getppid());
            sleep(1);
        }
    }
    else if (pid > 0) {
        printf("I am parent, my pid is = %d\n", getpid());
        sleep(9);
        printf("------------parent going to die---------");
    }
    else{
        perror("fork");
        return 1;
    }

    return 0;
}

