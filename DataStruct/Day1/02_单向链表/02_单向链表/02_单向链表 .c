#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkList.h"

//�Զ�����������
typedef struct PERSON {
	char name[64];
	int age;
	int score;
} Person;

void MyPrint(void* data) {
	Person* p = (Person*)data;
	printf("Name:%s  Age:%d Score = %d\n", p->name, p->age, p->score);
}
int main()
{

	//��������
	LinkList* list = Init_LinkList();

	//��������
	Person p1 = { "aaa", 18, 150 };
	Person p2 = { "bbb", 19, 104 };
	Person p3 = { "ccc", 10, 152 };
	Person p4 = { "ddd", 16, 140 };
	Person p5 = { "eee", 28, 120 };

	//���ݲ�������
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	
	//��ӡ
	Print_LinkList(list, MyPrint);

	//ɾ��3
	RemoveByPos_LinkList(list, 3);
	

	//��ӡ
	printf("---------\n");
	Print_LinkList(list, MyPrint);


	//���ص�һ���ڵ�
	printf("---------\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name: %s  Age:%d  Score:%d\n", ret->name, ret->age, ret->score);

	//��������
	FreeSpace_LinkList(list); 

	 


	system("pause");
	return EXIT_SUCCESS;
}