/***********************************************************
  > File Name: gdbtest.c
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年01月22日 星期五 10时17分37秒
    > Modified Time:2021年01月22日 星期五 11时35分56秒
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define N 10

char* str = "hello";
int var = 0;

void init_arr(int* arr, int len)
{
    int i = 0;

    for(i=0; i < len; i++)
    {
        arr[i] = rand() % 20 + 1;

    }
}

void select_sort(int* arr, int len)
{
    int i, j, k, tmp;
    for(i = 0; i < len - 1; i++){
        k = i;
        for(j = i + 1; j < len; j++){
            if(arr[k] > arr[j])
                k = j;

        }

        if(i != k){
            tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
        }

    }
}

void print_arr(int *arr, int len){
    int i;
    for (i = 0; i < len; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}



int main(int argc,char* argv[])
{
    printf("%s %s %s \n", argv[1], argv[2], argv[3]);

    int arr[N];
    char* p = "hellod";

    srand(time(NULL));
    init_arr(arr, N);
    print_arr(arr, N);
    
    select_sort(arr, N);
    printf("----------after sort ------------------\n");
    print_arr(arr, N);


    return 0;
}

