/***********************************************************
  > File Name: testMkfifo.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月29日 星期五 19时30分13秒
    > Modified Time:2021年01月29日 星期五 19时31分57秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    int ret = mkfifo("mytestfifo", 0664);
    if(ret == -1)
        sys_err("mkfifo error");


    return 0;
}

