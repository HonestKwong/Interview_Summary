#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

#define MAX 10

//创建数组
int* CreateArray() {
	srand((unsigned int)time(NULL));
	int * arr = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}

	return arr;
}

//打印
void PrintArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//合并算法

void Merge(int* arr, int start, int end, int mid, int *tmp) {
	int i_start = start;
	int j_start = mid + 1;
	int i = start;

	//标识辅助空间有多少元素
	int length = 0;
	while (i_start <= mid && j_start <= end) {
		if (arr[i_start] <= arr[j_start]) {
			tmp[length] = arr[i_start];
			i_start++;
		}
		else {
			tmp[length] = arr[j_start];
			j_start++;
		}
		length++;
	}
	
	while (i_start <= mid) {
		tmp[length] = arr[i_start];
		length++;
		i_start++;
	}
	while (j_start <= end) {
		tmp[length] = arr[j_start];
		length++;
		j_start++;
	}

	for (int i = 0; i < length; i++) {
		arr[i+start] = tmp[i];
	}

}

//归并排序
void MergeSort(int arr[], int start, int end, int *tmp) {
	int mid = (start + end) / 2;
	//分组
	//左半边
	if (start >= end) return; 
	MergeSort(arr, start, mid, tmp);
	//右半边
	MergeSort(arr, mid + 1, end, tmp);

	//合并
	Merge(arr, start, end, mid, tmp);


}

int main()
{
	int* myArr = CreateArray();
	PrintArray(myArr, MAX);
	//辅助空间 
	int * tmp = (int*)malloc(sizeof(int) * MAX);
	MergeSort(myArr, 0, MAX - 1, tmp);
	PrintArray(myArr, MAX);


	//释放空间
	free(tmp);
	free(myArr);



	system("pause");
	return EXIT_SUCCESS;
}