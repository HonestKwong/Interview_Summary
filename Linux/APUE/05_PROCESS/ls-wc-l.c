/***********************************************************
  > File Name: ls-wc-l.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月28日 星期四 21时59分55秒
    > Modified Time:2021年01月29日 星期五 22时05分15秒
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

    pid_t pid;
    int ret;
    int fd[2];
    ret = pipe(fd);           //父进程先创建一个管道,持有管道的读端和写端
    if(ret == -1) sys_err("pipe error");
    pid = fork();     //子进程同样持有管道的读和写端
    if(pid < 0) perror("fork error");
    else if(pid > 0){               //父进程 读, 关闭写端
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);   // 重定向 stdin 到管道的读端
        execlp("wc", "wc", "-l", NULL);   //执行 wc -l 程序
        sys_err("execlp error");
    }
    else if(pid == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);  // 重定向 stdout 到管道的写端
        execlp("ls", "ls", NULL);   //ls 写入管道
        sys_err("execlp error");
    }
    return 0;
}

