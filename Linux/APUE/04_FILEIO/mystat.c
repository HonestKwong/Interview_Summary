/***********************************************************
  > File Name: mystat.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 21时11分02秒
    > Modified Time:2021年01月25日 星期一 13时56分31秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc,char* argv[])
{
    struct stat sbuf;
    int ret = lstat(argv[1], &sbuf);
    if(ret == -1){
        perror("stat error");
        exit(1);
    }

    printf("file size: %ld\n", sbuf.st_size);

    if(S_ISREG(sbuf.st_mode)){
        printf("It's a regular file\n");
    }
    else if(S_ISDIR(sbuf.st_mode)){
        printf("It's a dir file\n");
    } 
    else if(S_ISFIFO(sbuf.st_mode)){
        printf("It's a pipe\n");
    }
    else if(S_ISLNK(sbuf.st_mode)){
        printf("It's a soft link\n");
    }
     

    return 0;
}

