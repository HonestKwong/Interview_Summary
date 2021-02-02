/***********************************************************
  > File Name: ls-wc-l.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月28日 星期四 21时59分55秒
    > Modified Time:2021年01月29日 星期五 22时09分07秒
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
    int i;
    int ret;
    int fd[2];
    ret = pipe(fd);
    if(ret == -1) sys_err("pipe error"); //表达式2 出口, 仅限父进程使用
    for(i = 0; i < 2; i++) {
        pid = fork();
        if(pid < 0) perror("fork error");
        if(pid == 0) break;   //子进程出口
    }
    
    if(i == 2) {    //父进程, 不参与管道使用的.

        close(fd[0]);    //关闭管道的 读端/写端
        close(fd[1]);
        wait(NULL);           //只关一个是可以的,只是不符合单向流动
        wait(NULL);        //回收子进程
    }
    else if(i == 0) {  //哥哥进程
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);  //重定向stdout
        execlp("ls", "ls", NULL);
        sys_err("execlp error");

    }
    else if (i == 1) {   //弟弟进程
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);    //重定向stdin
        execlp("wc", "wc", "-l", NULL);
        sys_err("execlp error");
    }
    return 0;
}

