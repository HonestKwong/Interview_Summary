#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "LinkStack.h"

//�ж��Ƿ�������
int IsNumber(char c) {
	return c >= '0' && c <= '9';
}

//���ֲ���
void NumberOperate(char* c) {
	printf("%c ", *c);
}

//�ж��Ƿ�������
int IsLeft(char c) {
	return c == '(';
}

//�ж��Ƿ�������
int IsRight(char c) {
	return c == ')';
}

//�ж��ǲ����������
int IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//��������������ȼ�
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

//����MyChar
MyChar* CreateMyChar(char* p) {
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->p = p;
	return mychar;
}

//�����ŵĲ���
void LeftOperate(LinkStack* stack, char* p) {
	Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

//�����ŵĲ���
void RightOperate(LinkStack* stack) {
	//���ж�ջ������Ԫ��
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		//���ƥ�䵽������
		if (IsLeft(*(mychar->p))) {
			Pop_LinkStack(stack);
			free(mychar);
			break;
		}
		//���
		printf("%c", *(mychar->p));
		//����  
		Pop_LinkStack(stack);
		//�ͷ��ڴ�
		free(mychar);
	}
}

//���������
void OperatorOperate(LinkStack* stack,char* p) {
	//��ȡ��ջ������
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	// ���ջ�����ȼ����ڵ�ǰ�ַ������ȼ� ֱ����ջ
	if (mychar == NULL) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	if (GetPriority(*(mychar->p))< GetPriority(*p)) {
		Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
		return;
	}
	//���ջ���������ȼ�����
	else {
		while (Size_LinkStack(stack) > 0) {

			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			//������ȼ���
			if (GetPriority(*(mychar2->p)) < (GetPriority(*p))) {
				Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
				return;

			}

			//���
			printf("%c", *(mychar2->p));
			//����
			Pop_LinkStack(stack);
			//�ͷ�
			free(mychar2);
		}
	}
}
int main01()
{
	char* str = "8+(3-1)*5";
	char* p = str;

	//����ջ
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0') {
		//���������
		if (IsNumber(*p)) {
			NumberOperate(p);
		}

		//���������ֱ�ӽ�ջ
		if (IsLeft(*p)) {
			LeftOperate(stack, p);
		}

		if (IsRight(*p)) {
			RightOperate(stack);
		}
		//������������
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