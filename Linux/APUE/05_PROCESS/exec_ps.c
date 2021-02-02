/***********************************************************
  > File Name: exec_ps.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月27日 星期三 13时51分44秒
    > Modified Time:2021年01月27日 星期三 14时20分26秒
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
    int fd;
    
    fd = open("ps.out", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd < 0) {
        perror("open ps.out error");
        exit(1);
    }

    dup2(fd, STDOUT_FILENO);

    execlp("ps", "ps", "ax", NULL);
    
    perror("execlp error");

    return 0;
}

