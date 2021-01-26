/***********************************************************
  > File Name: fcntl_dup.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月25日 星期一 22时16分22秒
    > Modified Time:2021年01月25日 星期一 22时25分09秒
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
    int fd1 = open(argv[1], O_RDWR);

    printf("fd1 = %d\n", fd1);

    int newfd = fcntl(fd1, F_DUPFD, 0); //0 已经被占用, fcntl使用文件描述表中可用的最小文件描述符返回.
    printf("newfd = %d\n", newfd);
    int newfd1 = fcntl(fd1, F_DUPFD, 7);

    printf("newfd1 = %d\n", newfd1); // 7 未被占用, 返回>=7的文件描述符

    int ret = write(newfd, "YYYYYYY", 7);
    printf("ret = %d \n", ret);
    close(fd1);
    close(newfd);
    close(newfd1);

    return 0;
}

