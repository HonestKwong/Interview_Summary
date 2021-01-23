/***********************************************************
  > File Name: test.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月21日 星期四 11时09分53秒
    > Modified Time:2021年01月21日 星期四 11时47分41秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#include "mymath.h"

int mul(int a, int b){

    return a * b;
}
int main(int argc,char* argv[])
{
    int a = 14, b = 6;

    printf("%d+%d=%d\n", a, b, add(a,b));
    printf("%d-%d=%d\n", a, b, sub(a,b));
    printf("%d/%d=%d\n", a, b, div1(a,b));
    printf("--%d x %d = %d\n", a, b, mul(a, b)); 
    return 0;
}

