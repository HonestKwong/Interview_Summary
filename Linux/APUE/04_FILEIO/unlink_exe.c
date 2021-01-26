/***********************************************************
  > File Name: unlink_exe.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月25日 星期一 14时49分11秒
    > Modified Time:2021年01月25日 星期一 15时18分42秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    int fd, ret;
    char* p = "test of unlink\n";
    char* p2 = "after write something.\n";

    fd = open("temp.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);
    if(fd < 0){
        perror("open temp error");
        exit(1);
    }

    ret = unlink("temp.txt");
    if (ret<0) {
        perror("unlink error");
        exit(1);
    }

    ret = write(fd, p, strlen(p));
    if(ret == -1){
        perror("-----write error");
    }

    printf("hi! I'm printf\n");
    ret = write(fd, p2, strlen(p2));
    if(ret == -1){
        perror("-----write error");
        
    }

    p[3] = 'H';

    printf("Enter anykey continue\n");
    getchar();
    close(fd);


    return 0;
}

