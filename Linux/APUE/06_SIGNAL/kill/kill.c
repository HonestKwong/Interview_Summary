/***********************************************************
  > File Name: kill.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月31日 星期日 20时43分07秒
    > Modified Time:2021年01月31日 星期日 20时54分28秒
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

int main(int argc,char* argv[])
{
    pid_t pid = fork();
    if(pid) {
        printf("parent, pid = %d\n", getpid());
        while(1);
    }
    else if(pid == 0) {
        printf("child pid = %d , ppid = %d\n", getpid(), getpid());
        sleep(2); 
        //kill(getppid(), SIGKILL);
        //kill(getppid(),  SIGSEGV);
        //kill(getppid(),  SIGCHLD);
        kill(0, SIGKILL);
    }

    return 0;
}

