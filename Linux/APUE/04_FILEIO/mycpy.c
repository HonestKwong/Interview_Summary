/***********************************************************
  > File Name: mycpy.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 14时46分23秒
    > Modified Time:2021年01月24日 星期日 15时35分11秒
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

    char buf[1024];
    int n = 0;

    int fd1 = open(argv[1], O_RDONLY);
    if(fd1 < 0) {
        perror("open argv1 error");
        exit(1);
    }
    int fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fd2 < 0) {
        perror("open argv2 error");
        exit(1);
    } 

    
    while((n = read(fd1, buf, 1024)) != 0){
        if (n < 0){
            perror("read error");
            break;

        }
        write(fd2, buf, n);


    }


    close(fd1);
    close(fd2);
    return 0;
}

