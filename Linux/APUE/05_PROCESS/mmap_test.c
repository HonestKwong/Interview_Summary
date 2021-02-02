/***********************************************************
  > File Name: mmap.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 22时20分57秒
    > Modified Time:2021年01月30日 星期六 21时51分00秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>


void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    char* p = NULL;
    int fd;

    fd = open("testmap", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        sys_err("open error");
    /*
    lseek(fd, 10, SEEK_END);   //两个函数等价与ftruncate()函数
    write(fd, "\0", 1);
    */

    ftruncate(fd, 20);   // fruncate需要写权限才能扩展文件大小 

    int len = lseek(fd, 0, SEEK_END);
    printf("file len = %d\n", len);
    
    //int len = 0;

    p = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED) 
        sys_err("mmap error");
    //使用 p 对 文件进行读写操作.
    
    strcpy(p, "hello mmap");

    printf("------%s\n", p);

    int ret = munmap(p, len);
    if(ret == -1)
        sys_err("munmap error");
    close(fd);

    return 0;
}

