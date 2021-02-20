/***********************************************************
  > File Name: event.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月18日 星期四 09时18分08秒
    > Modified Time:2021年02月18日 星期四 09时26分52秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <event2/event.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    struct event_base *base = event_base_new();
    int i;
    const char** buf;
    const char *buf2;
    /*buf = event_get_supported_methods();
    for(i = 0; i < 10; i++) {
        printf("buf[i] = %s\n", buf[i]);
    }
    */

    buf2 = event_base_get_method(base);
    printf("tmp used method: %s", buf2);

    return 0;
}

