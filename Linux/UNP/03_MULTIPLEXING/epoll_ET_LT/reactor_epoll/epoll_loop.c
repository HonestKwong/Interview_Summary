/***********************************************************
  > File Name: epoll_loop.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月12日 星期五 22时30分39秒
    > Modified Time:2021年02月14日 星期日 09时49分15秒
 *******************************************************/

/*
 * epoll基于非阻塞I/O事件驱动
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>


#define MAX_EVENTS 1024             //监听上限数
#define BUFLEN 4096
#define SERV_PORT 8080
void recvdata(int fd, int events, void* arg);
void senddata(int fd, int events, void* arg);

/* 描述就绪文件描述符相关信息 */

struct myevent_s {
    int fd;                        //要监听的文件描述符
    int events;                    //对应的监听事件
    void* arg;                     //泛型参数
    void (*call_back)(int fd, int events, void* arg);   //回调函数
    int status;     //是否在监听: 1-> 在红黑树上(监听), 0 -> 不在(不监听)
    char buf[BUFLEN];
    int len;                 
    long last_active;            //记录首次加入红黑树 g_efd 的时间值
};

int g_efd;      //全局变量, 保存epoll create 返回的文件描述符
struct myevent_s g_events[MAX_EVENTS+1];   //自定义结构体类型数据  +1 --> listenfd

void eventset(struct myevent_s* ev, int fd, void(*call_back)(int, int, void*), void* arg){
    ev->fd = fd;
    ev->call_back = call_back;
    ev->events = 0;
    ev->arg = arg;
    ev->status = 0;
    if(ev->len <=0){               //在设置的时候不能随意清空数据长度和缓冲区, 不然就转发不了!!!!!!!!!!
        memset(ev->buf, 0, sizeof(ev->buf));
        ev->len = 0;
    }
    ev->last_active = time(NULL);   //调用eventset函数的时间

    return;
}

/* 向 epoll监听的红黑树 添加一个文件描述符 */
//eventadd(efd, EPOLLIN, &g_events[MAX_EVENTS]);

void eventadd(int efd, int events, struct myevent_s* ev) 
{
    struct epoll_event epv = {0, {0}};
    int op;
    epv.data.ptr = ev;
    epv.events = ev->events = events; // EPOLLIN 或 EPOLLOUT

    if(ev->status == 0) {     //已经在红黑树g_efd 里
        op = EPOLL_CTL_ADD;   //将其加入红黑树 g_efd, 并将status置1
        ev->status = 1; 
    }

    if(epoll_ctl(efd, op, ev->fd, &epv) < 0)    //实际添加/修改
        printf("event add failed [fd = %d], events[%d]\n", ev->fd, events);
    else 
        printf("event add OK[fd = %d], op = %d, events[%0X]\n", ev->fd, op, events);

    return;
}

/* 从epoll监听的红黑树中删除一个文件描述符 */

void eventdel(int efd, struct myevent_s*ev)
{
    struct epoll_event epv = {0,{0}};

    if(ev->status != 1)    //不在红黑树上
        return;

    //epv.data.ptr = ev;
    epv.data.ptr = NULL;
    ev->status = 0;     //修改状态
    epoll_ctl(efd, EPOLL_CTL_DEL, ev->fd, &epv);  //从红黑树efd上将ev->fd摘除

    return;
}

/*当有文件描述符就绪, epoll返回, 调用该函数 与客户端建立链接 */

void acceptconn(int lfd, int events, void* arg)
{
    struct sockaddr_in cin;   //客户端 地址
    socklen_t len = sizeof(cin);
    int cfd, i;

    if((cfd = accept(lfd, (struct sockaddr*)&cin, &len)) == -1) {
        if(errno != EAGAIN && errno != EINTR) {
            /* 暂时不做出错处理 */
        }
        printf("%s: accept, %s\n", __func__, strerror(errno));
        //__LINE__
        return;
    }

    do {
        for(i = 0; i < MAX_EVENTS; i++)   //从全局数组g_events 中找一个空闲元素
            if(g_events[i].status == 0)  //类似与select中找值为-1 的元素
                break;    //跳出 for

        if(i == MAX_EVENTS) {
            printf("%s: max connect limit[%d]\n", __func__, MAX_EVENTS);
            break;      //跳出do while(0)  不执行后续代码
        }

        int flag = 0;
        if ((flag = fcntl(cfd, F_SETFL, O_NONBLOCK)) < 0) {
            //将cfd 也设置为非阻塞
            printf("%s: fcntl nonblocking failed, %s\n", __func__, strerror(errno));
            break;
        }

        /* 给cfd设置一个 myevent_s 结构体, 回调函数 设置为recvdata */
        eventset(&g_events[i], cfd, recvdata, &g_events[i]);
        eventadd(g_efd, EPOLLIN, &g_events[i]);  //将 cfd 添加到红黑树g_efd中, 监听读事件
    } while(0);

    printf("new connect [%s:%d][time:%ld], pos[%d]\n", inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), g_events[i].last_active, i);
    return;
}


void recvdata(int fd, int events, void *arg)
{
    struct myevent_s* ev = (struct myevent_s*)arg;
    int len;

    len = recv(fd, ev->buf, sizeof(ev->buf), 0);  //读文件描述符, 数据存入myevent_s 成员buf中
    eventdel(g_efd, ev);     //将该节点从红黑树上删除

    if(len > 0)
    {
        ev->len = len;
        ev->buf[len] = '\0';    //手动添加字符串结束标记
        printf("C[%d]:%s\n", fd, ev->buf);

        eventset(ev, fd, senddata, ev);  //设置该fd对应的回调函数为senddata
        eventadd(g_efd, EPOLLOUT, ev);   //将fd加入红黑树g_efd中, 监听其写事件
    }
    else if(len == 0) {
        close(ev->fd);
        /* ev-g_events 地址相减得到偏移元素位置*/
        printf("[fd=%d] pos[%ld], closed\n", fd, ev-g_events);
        
    }
    else 
    {
        close(ev->fd);
        printf("recv[fd=%d] error[%d]:%s\n", fd, errno, strerror(errno));
    }
    return;
}

void senddata(int fd, int events, void* arg)
{
    struct myevent_s* ev = (struct myevent_s*)arg;
    int len;

    len = send(fd, ev->buf, ev->len, 0);   //直接将数据 回写给客户端, 未作处理
    //printf("send[fd=%d], [%d]\n", fd, len);
    //printf("send[fd=%d], [%d]%s\n", fd, len, ev->buf);
    //这里ev 的buf中没有数据

    eventdel(g_efd, ev);

    if(len > 0) {
        printf("send[fd=%d], [%d]%s\n", fd, len, ev->buf);
        eventset(ev, fd, recvdata, ev);  //将该fd 的回调函数改为 recvdata
        eventadd(g_efd, EPOLLIN, ev);    //从新添加到红黑树上,设为监听读事件
    }
    else {
        close(ev->fd);       //关闭连接
        printf("send[fd=%d] error %s\n", fd, strerror(errno));
    }
    return;
}


/* 创建 socket , 初始化fd */
void initlistensocket(int efd, short port)
{
    struct sockaddr_in sin;

    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(lfd, F_SETFL, O_NONBLOCK);   //将socket设为非阻塞

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    bind(lfd, (struct sockaddr*)&sin, sizeof(sin));

    listen(lfd, 20);

    /* void eventset(struct myevent_s* ev, int fd, void(*void_back)(int, int, void*), void *arg); */
    eventset(&g_events[MAX_EVENTS], lfd, acceptconn, &g_events[MAX_EVENTS]);

    /* void eventadd(int efd, int events, struct myevent_s*ev)*/
    eventadd(efd, EPOLLIN, &g_events[MAX_EVENTS]);

    return;
}

int main(int argc,char* argv[])
{
    unsigned short port = SERV_PORT;

    if(argc == 2)
        port = atoi(argv[1]);      //使用用户指定端口,如未指定, 用默认端口

    g_efd = epoll_create(MAX_EVENTS+1);   //创建红黑树, 返回全局g_efd
    if(g_efd <= 0)
        printf("create efd in %s err %s\n", __func__, strerror(errno));

    initlistensocket(g_efd, port);   //初始化监听socket

    struct epoll_event events[MAX_EVENTS+1];  //保存已经满足就绪事件的文件描述符数组
    printf("server running:port[%d]\n", port);

    int checkpos = 0, i;
    while(1) {
        /*超时验证, 每次测试100个链接, 不测试listenfd 当客户端60秒内没有和服务器通信, 则关闭此客户端 */

        long now = time(NULL);    //当前时间
        for(i = 0; i < 100; i++, checkpos++) {  //一次循环检测100个, 使用checkpos控制检测对象 
            if(checkpos == MAX_EVENTS)
                checkpos = 0;
            if (g_events[checkpos].status != 1)   //不在红黑树g_efd上
                continue;

            long duration = now - g_events[checkpos].last_active;        //客户端不活跃的时间

            if (duration >= 60) {
                close(g_events[checkpos].fd);    //关闭与该客户端连接
                printf("[fd = %d] timeout\n", g_events[checkpos].fd);
                eventdel(g_efd, &g_events[checkpos]);     //将客户端从红黑树 g_efd移除
            }
        }
        /*  监听红黑树g_efd, 将满足的事件的文件描述符加至events数组中, 1 秒没有事件满足, 返回0 */
        int nfd = epoll_wait(g_efd, events, MAX_EVENTS+1, 1000);
        if (nfd < 0) {
            printf("epoll_wait error, exit\n");
            break;
        }

        for(i = 0; i < nfd; i++) {
            struct myevent_s* ev = (struct myevent_s*)events[i].data.ptr;
            /* 使用自定义结构体myevent_s类型指针, 接收 联合体data的void *ptr成员*/

            if((events[i].events & EPOLLIN) && (ev->events & EPOLLIN))         //读就绪
                ev->call_back(ev->fd, events[i].events, ev->arg);

            if((events[i].events & EPOLLOUT) && (ev->events & EPOLLOUT))      //写就绪
                ev->call_back(ev->fd, events[i].events, ev->arg);
        }
    }
    /* 退出释放所有资源*/

    return 0;
}

