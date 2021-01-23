/***********************************************************
  > File Name: hello.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月22日 星期五 13时29分19秒
    > Modified Time:2021年01月22日 星期五 16时21分10秒
 *******************************************************/
#include "hello.h"


int main(int argc,char* argv[])
{
    int a  = 16;
    int b = 5;
    printf("%d + %d = %d\n", a, b, add(a,b));
    printf("%d - %d = %d\n", a, b, sub(a,b));
    printf("%d / %d = %d\n", a, b, div1(a,b));
    printf("%d * %d = %d\n", a, b, mul(a,b));

    return 0;
}

