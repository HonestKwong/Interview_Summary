/***********************************************************
  > File Name: fifo_w.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 19时36分50秒
    > Modified Time:2021年01月29日 星期五 22时13分11秒
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
    int fd, len;
    char buf[4096];

    if(argc < 2) {
        printf("no fifo file input\n");
        return -1;
    }

    fd = open (argv[1], O_RDONLY);    //打开管道文件
    if(fd < 0)
        sys_err("open");
    while(1) {
        len = read(fd, buf, sizeof(buf));    //从管道的读端获取数据
        write(STDOUT_FILENO, buf, len);
        sleep(3);
    }

    close(fd);

    return 0;
}

