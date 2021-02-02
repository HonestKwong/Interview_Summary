/***********************************************************
  > File Name: alarm.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月31日 星期日 21时07分33秒
    > Modified Time:2021年01月31日 星期日 21时08分25秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    int i;
    alarm(1);

    for(i = 0; ;i++)
        printf("%d\n", i);

    return 0;
}

