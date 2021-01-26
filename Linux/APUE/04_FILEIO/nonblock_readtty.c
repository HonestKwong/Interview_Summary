/***********************************************************
  > File Name: block_readtty.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 16时46分19秒
    > Modified Time:2021年01月24日 星期日 17时10分19秒
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
    char buf[10];
    int fd, n;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        perror("open /dev/tty");
        exit(1);
    }

tryagain:

    n = read(fd, buf, 10);
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
    close(fd);
    return 0;
}

