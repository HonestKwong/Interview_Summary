/***********************************************************
  > File Name: fork.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月26日 星期二 21时16分42秒
    > Modified Time:2021年01月27日 星期三 14时35分50秒
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
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork error\n");
        exit(1);
    }
    else if (pid == 0) {
        //execlp("ls", "-l", "-d", "-h", NULL);
        //execlp("ls", "ls", "-l", "-h", NULL);
        //execlp("date", "date", NULL);
        //execl("./a.out", "a.out",  NULL);
        //execl("/bin/ls", "ls", "-l", NULL);
        char* argv1[] = {"ls", "-l", NULL};
        execvp("ls", argv1);
        perror("exec error");
        exit(1);

    }
    else if(pid > 0) {
        sleep(2);
        printf("I'm parent: %d\n", pid);
    }

    printf("end of file\n");
    return 0;
}

