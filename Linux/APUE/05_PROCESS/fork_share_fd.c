/***********************************************************
  > File Name: fork_share_fd.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 20时13分45秒
    > Modified Time:2021年01月29日 星期五 20时37分29秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    int fd1, fd2;
    pid_t pid;
    char buf[1024];
    char* str = "-------test for shared fd in parent child process---------\n";

    pid = fork();
    if(pid < 0) 
        sys_err("fork error");
    else if (pid == 0) {
        fd1 = open("test.txt", O_RDWR);
        if (fd1 < 0)
            sys_err("open error");
        sleep(1);
        write(fd1, str, strlen(str));
        printf("child wrote over....\n");
    }
    else {
        fd2 = open("test.txt", O_RDWR);
        if(fd2 < 0)
            sys_err("open_error");
        //sleep(1);

        int len = read(fd2, buf, sizeof(buf));
        printf("-----parent read len = %d\n", len);
        write(STDOUT_FILENO, buf, len);
        printf("-----parent read len = %d\n", len);

        wait(NULL);
    }

    return 0;
}

