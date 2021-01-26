/***********************************************************
  > File Name: dup.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月25日 星期一 21时47分50秒
    > Modified Time:2021年01月25日 星期一 22时09分55秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char* argv[])
{
    int fd1 = open(argv[1], O_RDWR);
    int fd2 = open(argv[2], O_RDWR);


    int fdret = dup2(fd1, fd2);
    printf("fdret = %d\n", fdret);

    //int ret = write(fd2, "1234567", 0);
    //printf("ret = %d\n", ret);

    dup2(fd1, STDOUT_FILENO);

    printf("------------------------886");
    
    close(fd1);
    close(fd2);
    close(fdret);


    return 0;
}

