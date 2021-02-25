#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 100000


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


void ShellSort(int arr[], int length) {
	int increasement = length;
	do {
		//确定分组的增量
		increasement = increasement / 3 + 1;
		int j = 0;
		int k = 0;
		for (int i = 0; i < increasement; i++) {
			for (j = i + increasement; j < length; j += increasement) {
				if (arr[j] < arr[j - increasement]) {
					int tmp = arr[j];
					for (k = j - increasement; k >= 0 && tmp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = tmp;
				}
			}
		}

	} while (increasement > 1);

}

int main()
{	
	int arr[MAX];
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	printf("排序前：\n");
	//PrintArray(arr, MAX);
	long t_start = getSystemTime();
	ShellSort(arr, MAX);
	long t_end = getSystemTime();
	printf("排序后：\n");
	//PrintArray(arr, MAX);
	printf("Sort nums: %d , Time Waste: %ld\n", MAX ,t_end - t_start);




	system("pause");
	return EXIT_SUCCESS;
}
