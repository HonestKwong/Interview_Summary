/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月17日 星期三 17时39分57秒
    > Modified Time:2021年02月17日 星期三 17时58分15秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include "wrap.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>
#define SERV_ADDR "serv.socket"


int main(int argc,char* argv[])
{
    int lfd, cfd, len, size, i;
    struct sockaddr_un servaddr, cliaddr;
    char buf[4096];

    lfd = Socket(AF_UNIX, SOCK_STREAM, 0);
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_UNIX;
    strcpy(servaddr.sun_path, SERV_ADDR);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(servaddr.sun_path);   //servaddr total len

    unlink(SERV_ADDR);
    Bind(lfd, (struct sockaddr*)&servaddr, len);

    Listen(lfd, 20);

    printf("Accept ...\n");

    while(1) {
        len = sizeof(cliaddr);   //AF_UNIX大小 + 108B
        cfd = Accept(lfd, (struct sockaddr*)&cliaddr, (socklen_t*)&len);

        len -= offsetof(struct sockaddr_un, sun_path);  //得到文件长度
        cliaddr.sun_path[len] = '\0';

        printf("client bind filename %s\n", cliaddr.sun_path);

        while((size = read(cfd, buf, sizeof(buf))) > 0) {
            for (i = 0; i < size; i++)
                buf[i] = toupper(buf[i]);
            write(cfd, buf, size);

        }
        close(cfd);
    }
    close(lfd);

    return 0;
}

