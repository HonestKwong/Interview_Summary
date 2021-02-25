#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "SeqQueue.h"

typedef struct PERSON {
	char name[64];
	int age;
}Person;

int main()
{
	//��������
	SeqQueue* queue = Init_SeqQueue();

	//��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 13;
	p2.age = 23;
	p3.age = 33;
	p4.age = 43;
	p5.age = 53;

	//���������
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);

	//���
	while (Size_SeqQueue(queue) > 0)
	{
		//ȡ����ͷԪ��
		Person* p = (Person*)Front_SeqQueue(queue);
		printf("Name: %s  Age:%d \n", p->name, p->age);
		p = (Person*)Back_SeqQueue(queue);
		printf("Name: %s  Age:%d \n", p->name, p->age);

		//�Ӷ�ͷ����Ԫ��
		Pop_SeqQueue(queue);
	}
	//���ٶ���
	Free_SeqQueue(queue);



	system("pause");
	return EXIT_SUCCESS;
}