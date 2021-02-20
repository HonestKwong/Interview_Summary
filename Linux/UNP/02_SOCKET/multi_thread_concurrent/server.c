/***********************************************************
  > File Name: server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月06日 星期六 19时36分32秒
    > Modified Time:2021年02月07日 星期日 14时51分23秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "wrap.h"
#include <ctype.h>
#include <sys/wait.h>

#define SRV_PORT 8000 
#define MAXLINE 8192

struct s_info {
    struct sockaddr_in cliaddr;
    int connfd;
};

void* do_work(void* arg)
{
    int n, i;
    struct s_info* ts = (struct s_info*)arg;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];

    while(1) {
        n = Read(ts->connfd, buf, MAXLINE);
        if (n == 0) {
            printf("the client %d closed ... \n", ts->connfd);
            break;
        }
        printf("recevied from %s at PORT %d\n", inet_ntop(AF_INET, &(*ts).cliaddr.sin_addr,str, sizeof(str)), ntohs((*ts).cliaddr.sin_port));

        for(i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);
        Write(STDOUT_FILENO, buf, n);
        Write(ts->connfd, buf, n);
    }

    Close(ts->connfd);
    //return (void*)0;
    pthread_exit(0);
}



int main(int argc,char* argv[])
{
    struct sockaddr_in srv_addr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    pthread_t tid;

    struct s_info ts[256];   //创建结构体数组
    int i = 0;
    char buf[BUFSIZ];

    listenfd= Socket(AF_INET, SOCK_STREAM, 0);    //创建一个socket, 得到lfd

    bzero(&srv_addr, sizeof(srv_addr));    //地址结构清零
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(SRV_PORT);     //指定本地任意IP
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);    //指定端口号

    Bind(listenfd, (struct sockaddr*)&srv_addr, sizeof(srv_addr));   //绑定


    Listen(listenfd, 128);               //设置同一时刻连接服务器上限数

    printf("Accepting client connect ....\n");




    while(1) {

        cliaddr_len =  sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr*)&cliaddr, &cliaddr_len);   //阻塞监听客户端链接请求
        ts[i].cliaddr = cliaddr;
        ts[i].connfd = connfd;
        pthread_create(&tid, NULL, do_work, (void*)&ts[i]);
        pthread_detach(tid);
        i++;

    }
    return 0;
}

