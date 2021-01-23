/***********************************************************
  > File Name: open.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月22日 星期五 21时43分01秒
    > Modified Time:2021年01月22日 星期五 22时08分21秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc,char* argv[])
{
    int fd;
    fd = open("./dict.txt", O_RDONLY , 0511);
     
    printf("fd = %d\n", fd);
    close(fd);
    return 0;
}

