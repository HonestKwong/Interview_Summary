/***********************************************************
  > File Name: mmap_w.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月30日 星期六 22时05分06秒
    > Modified Time:2021年01月30日 星期六 22时14分39秒
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
    struct student stu;
    struct student *p;
    int fd;
    fd = open("test_map", O_RDONLY);
    if(fd == -1)
        sys_err("open error");

    p = mmap(NULL, sizeof(stu), PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
        sys_err("mmap error");

    close(fd);

    while(1) {
        sleep(1);
        printf("id = %d, name = %s, age = %d\n", p->id, p->name, p->age);
    }

    munmap(p, sizeof(stu));


    return 0;
}

