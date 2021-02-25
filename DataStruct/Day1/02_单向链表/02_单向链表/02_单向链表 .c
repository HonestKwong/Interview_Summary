#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkList.h"

//自定义数据类型
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

	//创建链表
	LinkList* list = Init_LinkList();

	//创建数据
	Person p1 = { "aaa", 18, 150 };
	Person p2 = { "bbb", 19, 104 };
	Person p3 = { "ccc", 10, 152 };
	Person p4 = { "ddd", 16, 140 };
	Person p5 = { "eee", 28, 120 };

	//数据插入链表
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	
	//打印
	Print_LinkList(list, MyPrint);

	//删除3
	RemoveByPos_LinkList(list, 3);
	

	//打印
	printf("---------\n");
	Print_LinkList(list, MyPrint);


	//返回第一个节点
	printf("---------\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("Name: %s  Age:%d  Score:%d\n", ret->name, ret->age, ret->score);

	//销毁链表
	FreeSpace_LinkList(list); 

	 


	system("pause");
	return EXIT_SUCCESS;
}