/***********************************************************
  > File Name: pipe.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月28日 星期四 10时04分09秒
    > Modified Time:2021年01月28日 星期四 10时19分32秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    int ret;
    int fd[2];
    pid_t pid;

    ret = pipe(fd);
    if(ret == -1)
        sys_err("pipe error");

    pid = fork();
    char buf[1024];

    char* str = "hello pipe\n";

    if(pid > 0) {
        close(fd[0]);   //关闭读端
        write(fd[1], str, strlen(str));
        close(fd[1]);
        wait(NULL);   //防止返回终端
    }
    else if(pid == 0) {
        close(fd[1]);
        ret = read(fd[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        close(fd[0]);

    }
    return 0;
}

