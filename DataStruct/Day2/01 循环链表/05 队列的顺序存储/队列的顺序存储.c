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
	//创建队列
	SeqQueue* queue = Init_SeqQueue();

	//创建数据
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

	//数据入队列
	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);
	Push_SeqQueue(queue, &p5);

	//输出
	while (Size_SeqQueue(queue) > 0)
	{
		//取出对头元素
		Person* p = (Person*)Front_SeqQueue(queue);
		printf("Name: %s  Age:%d \n", p->name, p->age);
		p = (Person*)Back_SeqQueue(queue);
		printf("Name: %s  Age:%d \n", p->name, p->age);

		//从队头弹出元素
		Pop_SeqQueue(queue);
	}
	//销毁队列
	Free_SeqQueue(queue);



	system("pause");
	return EXIT_SUCCESS;
}