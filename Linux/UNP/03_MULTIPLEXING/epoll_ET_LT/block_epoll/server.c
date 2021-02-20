/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月11日 星期四 17时59分08秒
    > Modified Time:2021年02月12日 星期五 10时04分54秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/epoll.h>
#include <signal.h>

#define MAXLINE 10
#define SERV_PORT 9000


int main(int argc,char* argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int efd;

    listenfd =  socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));


    listen(listenfd, 20);

    struct epoll_event event;
    struct epoll_event resevent[10];
    int res, len;

    efd = epoll_create(10);
    //event.events = EPOLLIN | EPOLLET; // ET边沿触发
    event.events = EPOLLIN;    //默认LT触发
    
    printf("Accepting conncetions ...\n");

    cliaddr_len = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);
    printf("received from %s at PORT %d\n", 
            inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));

    event.data.fd = connfd;
    epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &event);

    while(1) {
        res = epoll_wait(efd, resevent, 10, -1);

        printf("res %d\n", res);
        if (resevent[0].data.fd == connfd) {
            len = read(connfd, buf, MAXLINE/2);
            write(STDOUT_FILENO, buf, len);
        }
    }

    return 0;
}

