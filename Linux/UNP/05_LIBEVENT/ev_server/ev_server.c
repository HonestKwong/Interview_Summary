/***********************************************************
  > File Name: ev_server.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月19日 星期五 13时13分11秒
    > Modified Time:2021年02月19日 星期五 13时56分50秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>

//读缓冲区回调
void read_cb(struct bufferevent *bev, void* arg)
{
    char buf[1024] = {0};

    bufferevent_read(bev, buf, sizeof(buf));
    printf("client say: %s\n", buf);

    char* p = "我是服务器, 已经成功收到你发送的数据!";

    //写数据给客户端
    bufferevent_write(bev, p, strlen(p) + 1);

    sleep(1);
}

//写缓冲区回调
void write_cb(struct bufferevent* bev, void* arg)
{
    printf("I'm server, Send data to client already, this function is ivoked");
}

//事件回调
void event_cb(struct bufferevent* bev, short events, void* arg)
{
    if (events & BEV_EVENT_EOF)
        printf("connection closed\n");
    else if (events & BEV_EVENT_ERROR)
        printf("some other error\n");

    bufferevent_free(bev);

    printf("buffevent resources freed already\n");
}

//监听回调
void cb_listener (
    struct evconnlistener* listener,
    evutil_socket_t fd, 
    struct sockaddr* addr,
    int len, void* ptr)
{
    printf("connect new client\n");

    struct event_base* base = (struct event_base*)ptr;

    //添加新事件
    struct bufferevent *bev;
    bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

    //给bufferevent缓冲区设置回调
    bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);

    //启用 bufferevent 的 读缓冲, 默认是disable的
    bufferevent_enable(bev, EV_READ);
}

int main(int argc,char* argv[])
{
    //init server
    struct sockaddr_in serv;

    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(9876);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //创建 event_base
    struct event_base* base;
    base = event_base_new();
    //创建套接字
    //绑定
    //接收连接请求
    struct evconnlistener* listener;   //监听器
    listener = evconnlistener_new_bind(base, cb_listener, base, 
            LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,
            36, (struct sockaddr*)&serv, sizeof(serv));

    //启动循环监听
    event_base_dispatch(base);

    evconnlistener_free(listener);    //监听器

    event_base_free(base);

    return 0;
}

