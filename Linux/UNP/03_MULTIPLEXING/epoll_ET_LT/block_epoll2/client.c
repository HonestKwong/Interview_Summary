/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月11日 星期四 17时59分08秒
    > Modified Time:2021年02月11日 星期四 18时49分56秒
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
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, i;
    char ch = 'a';

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket error:");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr.s_addr);
    servaddr.sin_port = htons(SERV_PORT);

    int ret = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(ret == -1) {
        perror("socket error:");
    }

    while(1) {
        //aaaa\n
        for (i = 0; i < MAXLINE/2; i++)
            buf[i] = ch;
        buf[i -1] = '\n';
        ch++;
        //bbbb\n
        for(; i < MAXLINE; i++)
            buf[i] = ch;
        buf[i-1] = '\n';
        ch++;
        //aaaa\nbbbb\n
        write(sockfd, buf, sizeof(buf));
        sleep(5);

    }
    close(sockfd);

    return 0;
}

