#include "DynamicArray.h"



//��ʼ��
Dynamic_Array* Init_Array() {
	//�����ڴ�
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	//��ʼ��
	myArray->capacity = 20;
	myArray->size = 0;
	myArray->pAddr = (int*)malloc(sizeof(int)*myArray->capacity);

	return myArray;
}
//����
void Push_Back_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL)
		return;
	// �ж��Ƿ��㹻
	if (arr->capacity == arr->size) {
		// ��һ��, �����¿ռ�
		int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		// �ڶ���, ����֮ǰ��Ԫ�ص� �¿ռ�
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		// ������, �ͷžɿռ�
		free(arr->pAddr);
		//��������
		arr->pAddr = newSpace;
		arr->capacity = arr->capacity * 2;
	}

	arr->pAddr[arr->size] = value;
	arr->size++;
}
//ɾ��
void Remove_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	//�ж�λ���Ƿ���Ч
	if (pos < 0 || pos > arr->size) {
		return;
	}
	//ɾ��Ԫ��
	for (int i = pos; i < arr->size - 1; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}
//����ֵɾ��
void RemovebyValue_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//����λ��
	int pos = Find_Array(arr, value);
	//����λ��ɾ��
	Remove_Array(arr, pos);
}

//����
int Find_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL) return -1;
	int pos = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}
	}
	return pos;
}
//��ӡ
void Print_Array(Dynamic_Array* arr) {
	for (int i = 0; i < arr->size; i++) {
		printf("%d ", arr->pAddr[i]);

	}
	printf("\n");
	return;
}
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array* arr) {
	if (arr == NULL) {
		return;
	}
	if (arr->pAddr != NULL) {
		free(arr->pAddr);
	}
	free(arr);
	return;
}

//�������
void Clear_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return;
	//pAddr-> �ռ�
	arr->size = 0;

}


//��ö�̬��������
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -1;
	return arr->capacity;
}

//��ö�̬���ݵ�ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -1;
	return arr->size;
}

//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL)
		return -1;

	return arr->pAddr[pos];
}
