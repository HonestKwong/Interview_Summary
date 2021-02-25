#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "CircleLinkList.h"


typedef struct PERSON {
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;

void MyPrint(CircleLinkNode* data) {
	Person* p = (Person*)data;
	printf("name: %s  age: %d  score: %d\n", p->name, p->age, p->score);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode*data2) {
	Person* p1 = (Person*)data1;
	Person* p2 = (Person*)data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score) {
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

int main()
{
	//����ѭ������
	CircleLinkList* clist = Init_CircleLinkList();
	
	//��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 11;
	p2.age = 12;
	p3.age = 13;
	p4.age = 14;
	p5.age = 15;


	p1.score = 51;
	p2.score = 52;
	p3.score = 53;
	p4.score = 54;
	p5.score = 55;


	//����������
	Insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
	Insert_CircleLinkList(clist, 1, (CircleLinkNode*)&p2);
	Insert_CircleLinkList(clist, 2, (CircleLinkNode*)&p3);
	Insert_CircleLinkList(clist, 3, (CircleLinkNode*)&p4);
	Insert_CircleLinkList(clist, 4, (CircleLinkNode*)&p5);

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);


	//����ֵɾ��
	Person pDel;
	strcpy(pDel.name, "ccc");
	pDel.age = 13;
	pDel.score = 53;

	RemoveByValue_CircleLinkList(clist, (CircleLinkNode*)&pDel, MyCompare);

	//��ӡ
	printf("---------------------------\n");
	Print_CircleLinkList(clist, MyPrint);

	//�ͷ��ڴ�
	FreeSpace_CircleLinkList(clist);

	system("pause");
	return EXIT_SUCCESS;
}