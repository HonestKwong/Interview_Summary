/***********************************************************
  > File Name: myread.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月18日 星期四 10时46分08秒
    > Modified Time:2021年02月18日 星期四 11时24分50秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <event2/event.h>
#include <sys/stat.h>
#include <sys/types.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

void read_cb(evutil_socket_t fd, short what, void* arg)
{
    char buf[BUFSIZ];
    int len = read(fd, buf, sizeof(buf));
    printf("what = read ? %s , read from write : %s\n", what & EV_READ ? "Yes": "NO",buf);
    return;
}


int main(int argc,char* argv[])
{
    //创建fifo
    unlink("testfifo");
    mkfifo("testfifo", 0644);

    //打开fifo的读端

    int fd = open("testfifo", O_RDONLY | O_NONBLOCK);
    if (fd == -1)
    {
        sys_err("open err");
    }
    //创建 event_base
    struct event_base* base = event_base_new();

    //创建 事件
    //struct event* event_new(struct event_base* base, evutil_socket_t fd, short what, event_call_back*, NULL);
    struct event* ev = NULL;
    ev = event_new(base, fd, EV_READ | EV_PERSIST,read_cb, NULL);

    //添加事件 到 event_base上
    // int event_add(struct event *ev, const struct timeval *tv);
    event_add(ev, NULL);
    

    //启动循环
    // int event_base_dispatch(struct event_base *base);
    event_base_dispatch(base);      //while(1)


    //销毁 event_base
    event_base_free(base);

    return 0;
}

