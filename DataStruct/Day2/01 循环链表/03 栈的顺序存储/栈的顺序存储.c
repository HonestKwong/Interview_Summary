#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "SeqStack.h"

typedef struct PERSON {
	char name[64];
	int age;
}Person;

int main()
{
	//创建栈
	SeqStack* stack = Init_SeqStack();
	
	//创建数据
	Person p1 = { "aaa" , 10};
	Person p2 = { "bbb" , 11};
	Person p3 = { "ccc" , 12};
	Person p4 = { "ddd" , 13};
	Person p5 = { "eee" , 14};

	//入栈
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	//输出
	while (Size_SeqStack(stack) > 0) {
		//从栈顶访问元素
		Person* person = (Person*)Top_SeqStack(stack);
		printf("Name: %s Age: %d\n", person->name, person->age);
		//弹出栈顶元素
		Pop_SeqStack(stack);
	}
	FreeSpace_SeqStack(stack);

	system("pause");
	return EXIT_SUCCESS;
}