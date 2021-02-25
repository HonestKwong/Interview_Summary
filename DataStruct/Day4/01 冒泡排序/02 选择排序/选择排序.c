#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <sys/timeb.h> 

#define MAX 20

long getSystemTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

//��������
void Swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	//int tmp = *a;
	//*a = *b;
	//*b = tmp;
}

void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ѡ������
void SelectSort(int arr[], int length) {
	//ѡ����������˽����Ĵ���, û�м��ٶ���
	int min = 0;
	for (int i = 0; i < length; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			Swap(&arr[min], &arr[i]);
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
	printf("����ǰ��\n");
	PrintArray(arr, MAX);
	long t_start = getSystemTime();
	SelectSort(arr, MAX);
	long t_end = getSystemTime();
	printf("�����\n");
	printf("Sort nums: %d , Time Waste: %ld\n", MAX ,t_end - t_start);
	PrintArray(arr, MAX);




	system("pause");
	return EXIT_SUCCESS;
}