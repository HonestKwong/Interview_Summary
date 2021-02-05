/***********************************************************
  > File Name: pthread_endof3.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月04日 星期四 16时21分03秒
    > Modified Time:2021年02月04日 星期四 16时31分17秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

void* tfn1(void* arg) {
    printf("thread 1 returning\n");
    return (void*)111;
}

void* tfn2(void* arg) {
    printf("thread 2 exiting\n");
    pthread_exit((void*)222);
}

void* tfn3(void* arg){
    while(1){
        printf("thread 3: 1'm going to die in 3 seconds ...\n");
        sleep(1);
        /* pthread_testcancel(); //自己添加取消点*/
    }
    return (void*)666;
}
void sys_err(const char* str)
{
	perror(str);
	exit(1);
}

int main(int argc,char* argv[])
{
    pthread_t tid;
    void* tret = NULL;

    pthread_create(&tid, NULL, tfn1, NULL);
    pthread_join(tid, &tret);
    printf("thread 1 exit code = %d\n\n", (int)tret);


    pthread_create(&tid, NULL, tfn2, NULL);
    pthread_join(tid, &tret);
    printf("thread 2 exit code = %d\n\n", (int)tret);

    pthread_create(&tid, NULL, tfn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &tret);
    printf("thread 3 exit code = %d\n\n", (int)tret);
    return 0;
}

