#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

void test01() {
	//初始化动态数组
	Dynamic_Array* myArray = Init_Array();

	//打印容量
	printf("数组容量:%d\n", Capacity_Array(myArray));
	printf("数组大小:%d\n", Size_Array(myArray));
	//插入元素
	for (int i = 0; i < 30; i++) {
		Push_Back_Array(myArray, i);
	}
	//打印
	Print_Array(myArray);

	printf("数组容量:%d\n", Capacity_Array(myArray));
	printf("数组大小:%d\n", Size_Array(myArray));

	//删除
	RemovebyValue_Array(myArray, 27);
	Remove_Array(myArray, 0);

	Print_Array(myArray);
	printf("数组容量:%d\n", Capacity_Array(myArray));
	printf("数组大小:%d\n", Size_Array(myArray));


	//查找 5 的位置
	int pos = Find_Array(myArray, 5);
	printf("5查找到:pos:%d\n", pos, At_Array(myArray, pos));


	//销毁
	FreeSpace_Array(myArray);
}
int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}