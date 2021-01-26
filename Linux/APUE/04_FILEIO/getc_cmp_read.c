/***********************************************************
  > File Name: getc_cmp_read.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 15时40分52秒
    > Modified Time:2021年01月24日 星期日 15时47分16秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
    FILE* fp, *fp_out;
    int n;
    fp = fopen("dict.txt", "r");
    if(fp == NULL){
        perror("fopen error");
        exit(1);
    }

    fp_out = fopen("dict.cp", "w");
    if(fp_out == NULL){
        perror("fopen error");
        exit(1);
    }

    while((n = fgetc(fp)) != EOF) {
        fputc(n, fp_out);
    }

    fclose(fp);
    fclose(fp_out);
     

    return 0;
}

