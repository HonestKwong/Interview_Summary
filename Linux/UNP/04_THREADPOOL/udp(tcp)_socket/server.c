/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月06日 星期六 12时03分33秒
    > Modified Time:2021年02月17日 星期三 15时51分44秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <ctype.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SERV_PORT 9527     //在网络环境中唯一标识一个进程

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

int main(int argc,char* argv[])
{
    int sockfd;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd < 0)
        sys_err("socket error");

    char buf[BUFSIZ], clie_IP[1024];

    int ret, i;
    struct  sockaddr_in serv_addr, clie_addr;
    socklen_t clie_addr_len;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    ret = bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret != 0)
        sys_err("bind error");


    clie_addr_len = sizeof(clie_addr);

    while(1) {
        ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&clie_addr, &clie_addr_len);

        inet_ntop(AF_INET, &clie_addr.sin_addr.s_addr, clie_IP, sizeof(clie_IP));
        printf("client ip:%s port:%d\n", clie_IP, ntohs(clie_addr.sin_port));
        write(STDOUT_FILENO, buf, ret);

        for(i = 0; i < ret; i++)
            buf[i] = toupper(buf[i]);

        sendto(sockfd, buf, ret, 0, (struct sockaddr*)&clie_addr, clie_addr_len);
    }


    close(sockfd);
    return 0;
}

