/***********************************************************
  > File Name: zoom.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月27日 星期三 14时51分39秒
    > Modified Time:2021年01月27日 星期三 14时55分59秒
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

    if (pid == 0) {
        printf("---child, my parent = %d, going to sleep 10s\n", getppid());
        sleep(10);
        printf("-----------child ide-------------\n");
    }
    else if (pid > 0) {
        while(1) {
            printf("I am parent, pid = %d, myson = %d\n", getpid(), pid);
            sleep(1);
        }
    }
    else  {
        perror("fork");
        return 1;
    }
      
                

    return 0;
}

