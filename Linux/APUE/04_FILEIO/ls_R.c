/***********************************************************
  > File Name: ls_R.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月25日 星期一 17时57分40秒
    > Modified Time:2021年01月26日 星期二 11时08分47秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define PATH_LEN 256 

void fetchdir(const char* dir, void(*fcn)(char*)){
    // 回调
    char name[PATH_LEN];
    struct dirent* sdp;
    DIR* dp;

    if((dp = opendir(dir)) == NULL) {
        //perror("fetchdir: can't open %s\n",dir);
        fprintf(stderr, "fetchdir: can't open %s\n", dir);
        return;
    }
    while((sdp = readdir(dp)) != NULL) {
        if(sdp->d_name[0] != '.'){  //不要访问.开头的文件
            if(strlen(dir) + strlen(sdp->d_name) + 2 > sizeof(name)) //限制目录长度
                fprintf(stderr, "fetchdir: name %s %s too long \n", dir, sdp->d_name);
            else{
                sprintf(name, "%s/%s", dir, sdp->d_name);
                (*fcn)(name);
            }
        }
    }

    closedir(dp); //这里要注意, 我一不小心把关文件写在循环里面了
}

void isfile(char* name)
    //主调
{
    struct stat sbuf;
    if(stat(name, &sbuf) == -1) {
        fprintf(stderr, "isfile: can't access %s\n", name);
        exit(1);
    }
    if ((sbuf.st_mode & S_IFMT) == S_IFDIR) {
        fetchdir(name, isfile);
    }

    printf("%8ld %s\n", sbuf.st_size, name);
}


int main(int argc,char* argv[])
{
    if(argc == 1)
        // isfile(".");
        fetchdir(".", isfile);
    else{
        while (--argc > 0)
            isfile(*++argv);
    }

    return 0;
}

