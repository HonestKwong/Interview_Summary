#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "LinkStack.h"

typedef struct MYCHAR {
	LinkNode node;
	char* pAddress;
	int index;
}MyChar;

int IsLeft(char c) {
	return c == '(';
}

int IsRight(char c) {
	return c == ')';
}

MyChar* CreateMyChar(char* p, int index) {
	MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
	mychar->pAddress = p;
	mychar->index = index;
	return mychar;
}

void ShowError(char* str, int pos) {
	printf("%s \n", str);
	for (int i = 0; i < pos; i++) {
		printf(" ");
	}
	printf("A\n");
}

int main()
{
	char* str = "1 + 2 + 6 (dsf)dfsflp((sdfd)";

	//����ջ����
	LinkStack* stack = Init_LinkStack();
	char* p = str;
	int index = 0;
	//����������� ֱ�ӽ�ջ
	while (*p != '\0') {
		if (IsLeft(*p)) {
			Push_LinkStack(stack, (LinkNode*)CreateMyChar(p, index));
		}
		//����������� ��ջ������Ԫ�� �ж��ǲ���������
		if (IsRight(*p)) {
			if (Size_LinkStack(stack) > 0) {
				MyChar* mychar = (MyChar*)Top_LinkStack(stack);
				if (IsLeft(*(mychar->pAddress))) {
					Pop_LinkStack(stack);
					free(mychar);
				}
			}
			else {
				printf("������û��ƥ���������:\n");
				ShowError(str, index);
				break;
			}
		}
		p++;
		index++;
	}

	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("������û��ƥ���������:\n");
		ShowError(str, mychar->index);
		Pop_LinkStack(stack);
		free(mychar);
	}
	


	system("pause");
	return EXIT_SUCCESS;
}