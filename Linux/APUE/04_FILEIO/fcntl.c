/***********************************************************
  > File Name: fcntl.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 17时49分07秒
    > Modified Time:2021年01月24日 星期日 18时01分27秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    char buf[10];
    int flags, n;

    flags = fcntl(STDIN_FILENO, F_GETFL);
    if(flags == -1){
        perror("fcntl error");
        exit(1);
    }

    flags |= O_NONBLOCK;
    int ret = fcntl(STDIN_FILENO, F_SETFL, flags);
    if(ret == -1){
        perror("fcntl error");
        exit(1);
        
    }

tryagain:
    n = read(STDIN_FILENO, buf, 10);
    if(n < 0){
        if(errno != EAGAIN){
            perror("read /dev/tty");
            exit(1);
        } else {
           write(STDOUT_FILENO, "try again\n", strlen("try again\n"));
           sleep(2);
           goto tryagain;
        }
    }
    write(STDOUT_FILENO, buf, n);

    return 0;
}

