#include "DynamicArray.h"



//初始化
Dynamic_Array* Init_Array() {
	//申请内存
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	//初始化
	myArray->capacity = 20;
	myArray->size = 0;
	myArray->pAddr = (int*)malloc(sizeof(int)*myArray->capacity);

	return myArray;
}
//插入
void Push_Back_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL)
		return;
	// 判断是否足够
	if (arr->capacity == arr->size) {
		// 第一步, 开辟新空间
		int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		// 第二部, 复制之前的元素到 新空间
		memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));
		// 第三步, 释放旧空间
		free(arr->pAddr);
		//更新容量
		arr->pAddr = newSpace;
		arr->capacity = arr->capacity * 2;
	}

	arr->pAddr[arr->size] = value;
	arr->size++;
}
//删除
void Remove_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	//判断位置是否有效
	if (pos < 0 || pos > arr->size) {
		return;
	}
	//删除元素
	for (int i = pos; i < arr->size - 1; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}
//根据值删除
void RemovebyValue_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//查找位置
	int pos = Find_Array(arr, value);
	//根据位置删除
	Remove_Array(arr, pos);
}

//查找
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
//打印
void Print_Array(Dynamic_Array* arr) {
	for (int i = 0; i < arr->size; i++) {
		printf("%d ", arr->pAddr[i]);

	}
	printf("\n");
	return;
}
//释放动态数组的内存
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

//清空数组
void Clear_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return;
	//pAddr-> 空间
	arr->size = 0;

}


//获得动态数组容量
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -1;
	return arr->capacity;
}

//获得动态数据当前元素个数
int Size_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -1;
	return arr->size;
}

//根据位置获得某个位置元素
int At_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL)
		return -1;

	return arr->pAddr[pos];
}
