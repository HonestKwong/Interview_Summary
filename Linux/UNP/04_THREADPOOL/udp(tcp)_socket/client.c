/***********************************************************
  > File Name: client.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月06日 星期六 13时07分30秒
    > Modified Time:2021年02月17日 星期三 15时55分10秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERV_PORT 9527

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
        sys_err("socket error");
    int ret;
    char buf[BUFSIZ];

    struct sockaddr_in serv_addr;

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr);



    while(1) {
        fgets(buf, sizeof(buf), stdin);
        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));   //这里必须使用strlen, 不然读数据会越界

        ret = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, 0);
        if (ret == -1)
            perror("recvfrom");

        write(STDOUT_FILENO, buf, ret);
        sleep(1);
        
    }

    close(sockfd);
    

    return 0;
}

