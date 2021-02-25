#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

#define MAX 10

//��������
int* CreateArray() {
	srand((unsigned int)time(NULL));
	int * arr = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}

	return arr;
}

//��ӡ
void PrintArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�ϲ��㷨

void Merge(int* arr, int start, int end, int mid, int *tmp) {
	int i_start = start;
	int j_start = mid + 1;
	int i = start;

	//��ʶ�����ռ��ж���Ԫ��
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

//�鲢����
void MergeSort(int arr[], int start, int end, int *tmp) {
	int mid = (start + end) / 2;
	//����
	//����
	if (start >= end) return; 
	MergeSort(arr, start, mid, tmp);
	//�Ұ��
	MergeSort(arr, mid + 1, end, tmp);

	//�ϲ�
	Merge(arr, start, end, mid, tmp);


}

int main()
{
	int* myArr = CreateArray();
	PrintArray(myArr, MAX);
	//�����ռ� 
	int * tmp = (int*)malloc(sizeof(int) * MAX);
	MergeSort(myArr, 0, MAX - 1, tmp);
	PrintArray(myArr, MAX);


	//�ͷſռ�
	free(tmp);
	free(myArr);



	system("pause");
	return EXIT_SUCCESS;
}