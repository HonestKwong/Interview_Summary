/***********************************************************
  > File Name: fifo_w.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 19时36分50秒
    > Modified Time:2021年01月29日 星期五 22时14分09秒
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
    int fd, i;
    char buf[4096];

    if(argc < 2) {
        printf("Enter like this: ./a.out fifoname\n");
        return -1;
    }

    fd = open (argv[1], O_WRONLY);   //打开管道文件
    if(fd < 0)
        sys_err("open");
    i = 0;
    while(1) {
        sprintf(buf, "hello mylove %d\n", i++);
        write(fd, buf, strlen(buf));   //向管道写数据
        sleep(1);
    }

    close(fd);

    return 0;
}

