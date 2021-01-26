/***********************************************************
  > File Name: mycpy.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 14时46分23秒
    > Modified Time:2021年01月24日 星期日 16时20分28秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

//#define N 1
#define N 1024

int main(int argc,char* argv[])
{
    int fd, fd_out;
    char buf[N];
    int n = 0;

    fd = open("dict.txt", O_RDONLY);
    if(fd < 0) {
        perror("open dict.txt error");
        exit(1);
    }
    fd_out = open("dict.cp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_out < 0) {
        perror("open dict.cp error");
        exit(1);
    } 

    
    while((n = read(fd, buf, N)) != 0){
        if (n < 0){
            perror("read error");
            break;

        }
        write(fd_out, buf, n);


    }


    close(fd);
    close(fd_out);
    return 0;
}

