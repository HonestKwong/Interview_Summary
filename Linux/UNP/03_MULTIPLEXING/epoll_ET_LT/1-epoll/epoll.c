/***********************************************************
  > File Name: epoll.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月11日 星期四 15时19分58秒
    > Modified Time:2021年02月12日 星期五 10时14分53秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>

#define MAXLINE 10


int main(int argc,char* argv[])
{
    int efd, i; 
    int pfd[2];
    pid_t pid; 
    char buf[MAXLINE], ch = 'a';

    pipe(pfd);
    pid = fork();

    if(pid == 0) {
        close(pfd[0]);
        while(1) {
            //aaaa \n
            for(i = 0; i < MAXLINE/2; i++)
                buf[i] = ch;
            buf[i-1] = '\n';
            ch++;
            //bbbb\n
            for(; i < MAXLINE; i++)
                buf[i] = ch;
            buf[i-1] = '\n';
            ch++;
            //aaaa\nbbbb\n
            write(STDOUT_FILENO, "child write!", 11);
            int ret = write(pfd[1], buf, sizeof(buf));
            if(ret == -1) 
            {
                perror("write error");
            }
            sleep(5);
        }
        close(pfd[1]);
    }

    else if(pid > 0) {
        struct epoll_event event;
        struct epoll_event resevent[10];     //epoll_wait就绪返回的event
        int res, len;

        close(pfd[1]);
        efd = epoll_create(10);

        event.events = EPOLLIN | EPOLLET;  //ET边沿触发
        //event.events = EPOLLIN;     //LT水平触发(默认)
        event.data.fd = pfd[0];
        epoll_ctl(efd, EPOLL_CTL_ADD, pfd[0], &event);

        int flg = fcntl(pfd[0], F_GETFL);
        flg |= O_NONBLOCK;
        fcntl(pfd[0], F_SETFL, flg);

        while(1) {
            res = epoll_wait(efd, resevent, 10, -1);
            printf("res %d \n", res);
            if (resevent[0].data.fd == pfd[0]) {
                while ((len = read(pfd[0], buf, MAXLINE/2)) > 0)
                write(STDOUT_FILENO, buf, len);
            }
        }

        close(pfd[0]);
        close(efd);
    }
    else {
        perror("fork error");
        exit(-1);
    }

    return 0;
}

