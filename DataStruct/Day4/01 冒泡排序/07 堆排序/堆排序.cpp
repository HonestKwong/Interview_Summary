#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//打印
void PrintArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void MySwap(int* a, int* b) {
	if (a == b) return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/*
	@param myArr 待调整的数组
	@param index 待调整的节点下标
	@param len 数组的长度

*/
void HeapAdjust(int arr[], int index, int len) {
	//先保存当前节点的下标
	int max = index;
	//保存左右孩子的数组下标
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;

	if (lchild < len && arr[lchild] < arr[max]) {
		max = lchild;
	}
	if (rchild < len && arr[rchild] < arr[max]) {
		max = rchild;
	}

	if (max != index) {
		//交换两个节点
		MySwap(&arr[max], &arr[index]);
		HeapAdjust(arr, max, len);  //交换完后往下调整
	}
}
//堆排序
void HeapSort(int* myArr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		HeapAdjust(myArr, i, len);
	}

	for (int i = len - 1; i >= 0; i--) {
		MySwap(&myArr[0], &myArr[i]);
		//这生产的更像是
		HeapAdjust(myArr, 0, i);
	}
	//cout << myArr[0] << endl;
}


int main()
{
	int MyArr[] = { 4,2,8,0,5,7,1,3,9 ,99, 100};
	int len = sizeof(MyArr) / sizeof(int);
	PrintArray(MyArr, len);

	//堆排序
	HeapSort(MyArr, len);
	PrintArray(MyArr, len);




	system("pause");
	return EXIT_SUCCESS;
}