/***********************************************************
  > File Name: test1.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 21时29分59秒
    > Modified Time:2021年01月29日 星期五 21时34分18秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

#define N 5

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    char buf[1024];
    char* str = "-----------str---------\n";
    int ret;

    int fd = open("test.txt", O_RDWR| O_TRUNC | O_CREAT, 0644);

    //直接打开文件写入数据
    write(fd, str, strlen(str));
    printf("test1 write into test.txt finsh\n");

    sleep(N);
    lseek(fd, 0, SEEK_SET);
    ret = read(fd, buf, sizeof(buf));
    ret = write(STDOUT_FILENO, buf, ret);

    if(ret == -1) 
        sys_err("write error");

    close(fd);
    return 0;
}

