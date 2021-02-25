#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicArray.h"

void test01() {
	//��ʼ����̬����
	Dynamic_Array* myArray = Init_Array();

	//��ӡ����
	printf("��������:%d\n", Capacity_Array(myArray));
	printf("�����С:%d\n", Size_Array(myArray));
	//����Ԫ��
	for (int i = 0; i < 30; i++) {
		Push_Back_Array(myArray, i);
	}
	//��ӡ
	Print_Array(myArray);

	printf("��������:%d\n", Capacity_Array(myArray));
	printf("�����С:%d\n", Size_Array(myArray));

	//ɾ��
	RemovebyValue_Array(myArray, 27);
	Remove_Array(myArray, 0);

	Print_Array(myArray);
	printf("��������:%d\n", Capacity_Array(myArray));
	printf("�����С:%d\n", Size_Array(myArray));


	//���� 5 ��λ��
	int pos = Find_Array(myArray, 5);
	printf("5���ҵ�:pos:%d\n", pos, At_Array(myArray, pos));


	//����
	FreeSpace_Array(myArray);
}
int main()
{
	test01();



	system("pause");
	return EXIT_SUCCESS;
}