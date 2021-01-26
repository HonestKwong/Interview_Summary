/***********************************************************
  > File Name: lseek_test.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 20时11分46秒
    > Modified Time:2021年01月24日 星期日 20时27分16秒
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
    int fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(1);
    }
    int len = lseek(fd, 110, SEEK_END);
    printf("file length: %d\n", len);

    write(fd, "\0", 1);
    close(fd);
        

    return 0;
}

                                                                                                               
