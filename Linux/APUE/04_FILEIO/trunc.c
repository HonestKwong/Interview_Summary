/***********************************************************
  > File Name: trunc.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 20时31分48秒
    > Modified Time:2021年01月24日 星期日 20时34分50秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
    //open/leek(fd, 249, SEEK_END); //write(fd, "\0",1);
    int ret = truncate("dict.cp",250);
    printf("ret = %d\n", ret);

    return 0;
}

