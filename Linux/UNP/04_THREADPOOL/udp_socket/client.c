/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月17日 星期三 12时42分55秒
    > Modified Time:2021年02月17日 星期三 15时15分42秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <ctype.h>

#define SERV_PORT 8000


int main(int argc,char* argv[])
{
    struct sockaddr_in servaddr;
    int sockfd, n;
    char buf[BUFSIZ];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    //bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));   //和服务端 绑到了同一端口

    while (fgets(buf, BUFSIZ, stdin) != NULL) {
        n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
        if (n == -1)
            perror("sendto error");

        n = recvfrom(sockfd, buf, BUFSIZ, 0, NULL, 0);
        if(n == -1)
            perror("recvfrom error");

        write(STDOUT_FILENO, buf, n);
    }

    close(sockfd);

    return 0;
}

