#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void PrintArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//快速排序 从小到大
void QuickSort(int arr[], int start, int end) {
	int i = start;
	int j = end;
	//基准数
	int tmp = arr[start];
	if (i < j) {  //这个 i < j 可以视作是一种退出条件
		while (i < j) {
			//从右向左找比基准数小的
			while (i < j && arr[j] >= tmp) {
				j--;
			}
			//填坑
			if (i < j) {
				arr[i] = arr[j];
				i++;  
			}
			while (i < j && arr[i] < tmp) {
				i++;
			}
			//填坑
			if (i < j) {
				arr[j] = arr[i];
				j--;  
			}
		}
		//把基准数放到i位置
		arr[i] = tmp;
		//对左半部分进行快速排序
		QuickSort(arr, start, i - 1);
		//对右半部分进行快速排序
		QuickSort(arr, i + 1, end);
	}
}

int main()
{
	int myArr[] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
	int len = sizeof(myArr) / sizeof(int);
	PrintArray(myArr, len);
	QuickSort(myArr, 0, len - 1);
	PrintArray(myArr, len);


	system("pause");
	return EXIT_SUCCESS;
}