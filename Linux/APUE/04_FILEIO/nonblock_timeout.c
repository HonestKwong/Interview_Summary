/***********************************************************
  > File Name: block_readtty.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 16时46分19秒
    > Modified Time:2021年01月24日 星期日 17时29分15秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#define MSG_TTY "try again\n"
#define MSG_TIMEOUT "time out\n"
int main(int argc,char* argv[])
{
    char buf[10];
    int fd, n, i;

    fd = open("/dev/tty", O_RDONLY | O_NONBLOCK); //重新打开
    if (fd < 0) {
        perror("open /dev/tty");
        exit(1);
    }
    printf("open /dev/ttf ok...%d\n", fd);



    for(i = 0; i < 5; i++){
        n = read(fd, buf, 10);
        if(n > 0) {
            break;
        }
        
        if(errno != EAGAIN){
            perror("read /dev/tty");
            exit(1);
        }
        else {
           write(STDOUT_FILENO, MSG_TTY, strlen(MSG_TTY));
           sleep(2);
        }
    }
    if(i == 5) {
       write(STDOUT_FILENO, MSG_TIMEOUT, strlen(MSG_TIMEOUT)); 
    }
    else
        write(STDOUT_FILENO, buf, n);
    close(fd);
    return 0;
}

