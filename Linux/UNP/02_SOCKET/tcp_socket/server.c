/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月06日 星期六 12时03分33秒
    > Modified Time:2021年02月06日 星期六 16时23分46秒
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

#define SERV_PORT 9527

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

int main(int argc,char* argv[])
{
    int i = 0;
    int lfd, cfd;
    int ret;
    char buf[BUFSIZ], client_IP_buf[1024];
    struct  sockaddr_in serv_addr, client_addr;
    socklen_t client_addr_len;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(lfd < 0)
        sys_err("socket error");

    ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret != 0)
        sys_err("accept error");

    listen(lfd, 128);

    client_addr_len = sizeof(client_addr);
    cfd = accept(lfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if(cfd < 0) 
        sys_err("accept error");

    inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_IP_buf, sizeof(client_IP_buf));

    printf("client ip:%s port:%d\n", client_IP_buf, ntohs(client_addr.sin_port));

    while(1) { 
        ret = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);

        for(i = 0; i < ret; i++)
            buf[i] = toupper(buf[i]);
        write(cfd, buf, ret);

    }
    close(lfd);
    close(cfd);
    return 0;
}

