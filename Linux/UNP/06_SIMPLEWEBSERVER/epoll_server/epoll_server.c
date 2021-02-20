/***********************************************************
  > File Name: epoll_server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月20日 星期六 16时44分48秒
    > Modified Time:2021年02月20日 星期六 17时02分04秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ctype.h>
#include "epoll_server.h"

#define MAXSIZE 2000

void send_error(int cfd, int status, char* title, char* text)
{
    char buf[4096] = {0};

    sprintf(buf, "%s %d %s\r\n", "HTTP/1.1", status, title);
    sprintf(buf + strlen(buf), "Content-Type:%s\r\n", "text/html");
    sprintf(buf + strlen(buf), "Content-Length:%d\r\n", -1);
    sprintf(buf + strlen(buf), "Connection: close\r\n"); 
    send(cfd, buf, strlen(buf), 0); 
    send(cfd, "\r\n", 2, 0); 

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "<html><head><title>%d %s</title></head>\n", status, title);
    sprintf(buf+strlen(buf), "<body bgcolor=\"#cc99cc\"><h4 align=\"center\">%d %s</h4>\n",status); 
    sprintf(buf+strlen(buf), "<hr>\n</body>\n</html>\n");
    send(cfd, buf, strlen(buf), 0);

    return;
}

void epoll_run(int port)
{

}

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{

    return 0;
}

