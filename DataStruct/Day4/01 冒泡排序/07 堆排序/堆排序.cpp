#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//��ӡ
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
	@param myArr ������������
	@param index �������Ľڵ��±�
	@param len ����ĳ���

*/
void HeapAdjust(int arr[], int index, int len) {
	//�ȱ��浱ǰ�ڵ���±�
	int max = index;
	//�������Һ��ӵ������±�
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;

	if (lchild < len && arr[lchild] < arr[max]) {
		max = lchild;
	}
	if (rchild < len && arr[rchild] < arr[max]) {
		max = rchild;
	}

	if (max != index) {
		//���������ڵ�
		MySwap(&arr[max], &arr[index]);
		HeapAdjust(arr, max, len);  //����������µ���
	}
}
//������
void HeapSort(int* myArr, int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		HeapAdjust(myArr, i, len);
	}

	for (int i = len - 1; i >= 0; i--) {
		MySwap(&myArr[0], &myArr[i]);
		//�������ĸ�����
		HeapAdjust(myArr, 0, i);
	}
	//cout << myArr[0] << endl;
}


int main()
{
	int MyArr[] = { 4,2,8,0,5,7,1,3,9 ,99, 100};
	int len = sizeof(MyArr) / sizeof(int);
	PrintArray(MyArr, len);

	//������
	HeapSort(MyArr, len);
	PrintArray(MyArr, len);




	system("pause");
	return EXIT_SUCCESS;
}