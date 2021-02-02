/***********************************************************
  > File Name: ls-wc-l.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月28日 星期四 21时59分55秒
    > Modified Time:2021年01月28日 星期四 23时20分33秒
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
    char buf[1024];
    int i, n;
    int ret;
    int fd[2];
    ret = pipe(fd);
    if(ret == -1) sys_err("pipe error"); //表达式2 出口, 仅限父进程使用
    for(i = 0; i < 2; i++) {
        pid = fork();
        if(pid < 0) perror("fork error");
        if(pid == 0) break;   //子进程出口
    }
    
    if(i == 0) {

        close(fd[0]);
        write(fd[1],"1.hello\n", strlen("1.hello\n"));
    }
    else if(i == 1) {  //哥哥进程
        close(fd[0]);
        write(fd[1], "2.hello\n", strlen("2.hello\n"));

    }
    else {   //弟弟进程
        close(fd[1]);
        sleep(1);
        n = read(fd[0], buf, 1024);
        write(STDOUT_FILENO, buf, n);

        for(i = 0; i < 2; i++) {
            wait(NULL);
        }
    }
    return 0;
}

