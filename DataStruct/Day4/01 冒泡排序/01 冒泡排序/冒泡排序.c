#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <sys/timeb.h> 

#define MAX 10

long getSystemTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//交换函数
void Swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	//int tmp = *a;
	//*a = *b;
	//*b = tmp;
}

static int flag = 0;
void BubbleSort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		flag = 1;
		for (int j = 0; j < length -i -1; j++) {
			if (arr[j + 1] > arr[j]) {
				Swap(&arr[j + 1], &arr[j]);
				flag = 0;
			}
		}
		if (flag) return;
	}
}

//打印函数
void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[MAX];
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	printf("排序前：\n");
	PrintArray(arr, MAX);
	long t_start = getSystemTime();
	BubbleSort(arr, MAX);
	long t_end = getSystemTime();
	printf("排序后：\n");
	printf("Sort nums: %d , Time Waste: %ld\n", MAX ,t_end - t_start);
	PrintArray(arr, MAX);

	system("pause");
	return EXIT_SUCCESS;
}