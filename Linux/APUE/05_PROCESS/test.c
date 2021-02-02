/***********************************************************
  > File Name: test.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月27日 星期三 11时53分07秒
    > Modified Time:2021年01月27日 星期三 12时32分43秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

void sys_err(const char* str){
    perror(str);
    exit(1);
}
int main(int argc,char* argv[])
{
    printf("------exec test \n");
    

    return 0;
}

