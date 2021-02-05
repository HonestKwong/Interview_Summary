/***********************************************************
  > File Name: daemon.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 11时27分40秒
    > Modified Time:2021年02月04日 星期四 11时37分29秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    pid_t pid;
    pid_t ret;
    int fd;

    pid = fork();
    if(pid > 0)     //父进程终止
        exit(0);
    ret = setsid(); //创建新的会话
    if (ret == -1) 
        sys_err("setsid error"); int ret2 = chdir("/home/kwong");  //改变工作目录位置
    if(ret2 == -1)
        sys_err("chdir err");

    umask(0022);   //改变文件访问掩码
    
    close(STDIN_FILENO);   //关闭文件描述符0
    fd = open("/dev/null", O_RDWR);   //fd ----> 0
    if(fd == -1)
        sys_err("open error"); 

    dup2(fd, STDOUT_FILENO);   //重定向stdout 和 stderr

    dup2(fd, STDERR_FILENO);

    while(1);     //模拟守护进程业务

    return 0;
}

