/***********************************************************
  > File Name: ls.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月25日 星期一 15时18分47秒
    > Modified Time:2021年01月25日 星期一 15时40分44秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>


int main(int argc,char* argv[])
{
    DIR* dp;
    struct dirent* sdp;
    int count = 0;     //用于五个一换行

    dp = opendir(argv[1]);
    if(dp == NULL) {
        perror("opendir perror ");
        exit(1);
    }
    while((sdp = readdir(dp)) != NULL) {
        if(sdp->d_name[0] != '.')
           printf("%-10s%c", sdp->d_name, ++count % 5 ? '\t' : '\n');
    }

    closedir(dp);  //一定注意别写成close了 


    return 0;
}

