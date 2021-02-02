/***********************************************************
  > File Name: test2.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 21时34分32秒
    > Modified Time:2021年01月29日 星期五 21时38分03秒
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
    char buf[1024];
    char* str = "--------------test2 write secesuss----------\n";
    int ret;

    sleep(2);

    int fd = open("test.txt", O_RDWR);

    //尝试读取test.txt文件中test1写入的数据
    ret = read(fd, buf, sizeof(buf));

    //将读到的数据打印到屏幕
    write(STDOUT_FILENO,buf, ret);
    
    write(fd, str, strlen(str));

    printf("test2 read/write finish\n");

    close(fd);
    return 0;
}

