#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkList.h"

typedef struct PERSON {
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data) {
	Person* p = (Person*)data;
	printf("name %s age:%d\n", p->name, p->age);
}

int MyCompare(LinkNode* node1, LinkNode* node2)
{
	Person* p1 = (Person*)node1;
	Person* p2 = (Person*)node2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
		return 0;
	}
	else return -1;
}

int main()
{
	//创建链表
	LinkList* list = Init_LinkList();

	//创建数据
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 11;
	p3.age = 13;
	p4.age = 15;
	p5.age = 17;

	//将节点插入链表
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);

	//打印
	Print_LinkList(list, MyPrint);

	//删除节点
	Remove_LinkList(list, 2);

	//打印
	printf("-----------\n");
	Print_LinkList(list, MyPrint);

	Person findP;
	strcpy(findP.name, "ccc");
	findP.age = 13;
	//查找
	int pos = Find_LinkList(list, (LinkList*)&findP, MyCompare);
	printf("位置%d\n", pos);

	//释放链表内存
	FreeSpace_LinkList(list);


	system("pause");
	return EXIT_SUCCESS;
}