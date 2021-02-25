#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "LinkStack.h"

//判断是否是数字
int IsNumber(char c) {
	return c >= '0' && c <= '9';
}

//数字操作
void NumberOperate(char* c) {
	printf("%c ", *c);
}

//判断是否左括号
int IsLeft(char c) {
	return c == '(';
}

//判断是否右括号
int IsRight(char c) {
	return c == ')';
}

//判断是不是运算符号
int IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//返回运算符号优先级
int GetPriority(char c) {
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	return 0;
}

typedef struct MYCHAR {
	LinkNode node;
	char* p;
}MyChar;

//创建MyChar
MyChar* CreateMyChar(char* p) {
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

//左括号的操作
void LeftOperate(LinkStack* stack, char* p) {
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

//右括号的操作
void RightOperate(LinkStack* stack) {
	//先判断栈中有无元素
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//如果匹配到左括号
		if (IsLeft(*(mychar->p))) {
			Pop_LinkStack(stack);
			free(mychar);
			break;
		}
		//输出
		printf("%c", *(mychar->p));
		//弹出  
		Pop_LinkStack(stack);
		//释放内存
		free(mychar);
	}
}

//运算符操作
void OperatorOperate(LinkStack* stack,char* p) {
	//先取出栈顶符号
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	// 如果栈顶优先级低于当前字符的优先级 直接入栈
	if (mychar == NULL) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	if (GetPriority(*(mychar->p))< GetPriority(*p)) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	//如果栈顶符号优先级不低
	else {
		while (Size_LinkStack(stack) > 0) {

			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			//如果优先级低
			if (GetPriority(*(mychar2->p)) < (GetPriority(*p))) {
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				return;

			}

			//输出
			printf("%c", *(mychar2->p));
			//弹出
			Pop_LinkStack(stack);
			//释放
			free(mychar2);
		}
	}
}
int main01()
{
	char* str = "8+(3-1)*5";
	char* p = str;

	//创建栈
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0') {
		//如果是数字
		if (IsNumber(*p)) {
			NumberOperate(p);
		}

		//如果左括号直接进栈
		if (IsLeft(*p)) {
			LeftOperate(stack, p);
		}

		if (IsRight(*p)) {
			RightOperate(stack);
		}
		//如果是运算符号
		if (IsOperator(*p)) {
			OperatorOperate(stack, p);

		}
		p++;
	}
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = Top_LinkStack(stack);
		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}

	FreeSpace_LineStack(stack);


	system("pause");
	return EXIT_SUCCESS;
}