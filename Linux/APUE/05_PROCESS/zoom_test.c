/***********************************************************
  > File Name: zoom.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月27日 星期三 14时51分39秒
    > Modified Time:2021年01月27日 星期三 19时33分47秒
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
    pid_t pid;
    pid = fork();
    int status;
    int wpid;

    if (pid == 0) {
        printf("---child, my parent = %d,my pid = %d, going to sleep 10s\n", getppid(), getpid());
        sleep(10);
        printf("-----------child ide-------------\n");
        return 73;
    }
    else if (pid > 0) {
        wpid = wait(&status); // 如果子进程未终止,父进程阻塞在这个函数上.
        //wpid = wait(NULL); //传NULL代表不关心返回的状态信息 
        if(wpid == -1) {
            perror("wait error");
            exit(1);
        }
        if(WIFEXITED(status)){ //为真说明子进程正常终止
            printf("child exit with %d \n", WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status)) { //为真, 说明子进程被信号终止.

            printf("child kill with signal %d \n", WTERMSIG(status));

        }
        printf("---------parent wait finish: %d\n", wpid);
    }
    else  {
        perror("fork");
        return 1;
    }
    return 0;
}

