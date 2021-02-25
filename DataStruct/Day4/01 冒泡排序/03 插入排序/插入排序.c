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


void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void InsertSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		if (arr[i] > arr[i-1]) {
			int j = 0;
			int tmp = arr[i];
			for (j = i - 1; j >= 0 && tmp > arr[j]; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}
}

int main()
{	
	int arr[MAX];
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	printf("ÅÅÐòÇ°£º\n");
	PrintArray(arr, MAX);
	long t_start = getSystemTime();
	InsertSort(arr, MAX);
	long t_end = getSystemTime();
	printf("ÅÅÐòºó£º\n");
	printf("Sort nums: %d , Time Waste: %ld\n", MAX ,t_end - t_start);
	PrintArray(arr, MAX);





	system("pause");
	return EXIT_SUCCESS;
}