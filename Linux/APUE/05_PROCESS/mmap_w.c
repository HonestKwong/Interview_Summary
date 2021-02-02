/***********************************************************
  > File Name: mmap_w.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月30日 星期六 22时05分06秒
    > Modified Time:2021年01月30日 星期六 22时20分44秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>


struct student {
    int id;
    char name[256];
    int age;
};

void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    struct student stu = {1, "xiaoming", 18};
    struct student *p;
    int fd;
    //fd = open("test_map", O_RDWR | O_CREAT | O_TRUNC, 0644);
    fd = open("test_map", O_RDWR );
    if(fd == -1)
        sys_err("open error");

    ftruncate(fd, sizeof(stu));

    p = mmap(NULL, sizeof(stu), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
        sys_err("mmap error");

    close(fd);

    while(1) {
        memcpy(p, &stu, sizeof(stu)); 
        stu.id++;
        sleep(2);
    }

    munmap(p, sizeof(stu));


    return 0;
}

