/***********************************************************
  > File Name: mymv.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月25日 星期一 14时45分05秒
    > Modified Time:2021年01月25日 星期一 14时45分43秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
    link(argv[1], argv[2]);

    unlink(argv[1]);

    return 0;
}

