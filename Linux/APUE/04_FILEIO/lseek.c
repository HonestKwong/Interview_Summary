/***********************************************************
  > File Name: lseek.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月24日 星期日 19时58分48秒
    > Modified Time:2021年01月24日 星期日 20时09分11秒
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
    int fd, n;
    char msg[] = "It's a test for lseek\n";
    char ch;

    fd = open("lseek.txt", O_RDWR | O_CREAT, 0644);
    if(fd < 0) {
        perror("open lseek.txt error");
        exit(1);
    }

    write(fd, msg, strlen(msg));   //使用fd对打开的文件进行写操作, 问
    lseek(fd, 0, SEEK_SET);   //修改文件读写指针, 位于文件开头. 注释该行会怎样?
    while((n = read(fd, &ch, 1))){
        if(n < 0){
            perror(" read error");
            exit(1);
            
        }
        write(STDOUT_FILENO, &ch, n); //将文件内容按字节读出,写到屏幕.
    }
    close(fd);

    return 0;
}

