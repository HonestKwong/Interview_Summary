/***********************************************************
  > File Name: client.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月06日 星期六 13时07分30秒
    > Modified Time:2021年02月06日 星期六 13时20分41秒
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
    int cfd;
    int counter = 10;
    cfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    char buf[BUFSIZ];

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr);

    if (cfd == -1)
        sys_err("socket error");
    int ret = connect(cfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if(ret != 0)
        sys_err("connect error");

    while(--counter) {
        write(cfd, "hello\n", 6);
        ret = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, ret);
        sleep(1);
        
    }

    close(cfd);
    

    return 0;
}

