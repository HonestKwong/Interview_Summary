/***********************************************************
  > File Name: block_readtty.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 16时46分19秒
    > Modified Time:2021年01月24日 星期日 16时49分45秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
    char buf[10];
    int n;

    n = read(STDIN_FILENO, buf, 10);
    if(n < 0){
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);

    return 0;
}

