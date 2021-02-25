#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "CircleLinkList.h"

#define M 8
#define N 3


typedef struct MYNUM {
	CircleLinkNode node;
	int val;
}MyNum;

void MyPrint(CircleLinkNode* data) {
	MyNum *p = (MyNum*)data;
	printf("%d ", p->val);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2) {
	MyNum *p1 = (MyNum*)data1;
	MyNum *p2 = (MyNum*)data2;
		
	if (p1->val == p2->val) {
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

int main()
{
	//����ѭ������
	CircleLinkList* clist = Init_CircleLinkList();
	//�����������  
	MyNum num[M];
	for (int i = 0; i < M; i++) {
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);

	}

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);

	printf("\n");

	//����ָ��
	int index = 1;
	CircleLinkNode* pCurrent = clist->head.next;

	while (Size_CircleLinkList(clist) > 1) {
		if (index == N) {
			MyNum* temNum = (MyNum*)pCurrent;
			printf("%d ", temNum->val);

			//�����ɾ���ڵ����һ���ڵ�
			CircleLinkNode* pNext = pCurrent->next;
			//����ֵɾ��
			RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
			pCurrent = pNext;
			if (pCurrent == &(clist->head)) {
				pCurrent = pCurrent->next;
			}
			index = 1;   
			continue;
		}
		pCurrent = pCurrent->next;     //����Ӧ���������ƶ�, ���ж��Ƿ�Ϊͷ�ڵ�
		if (pCurrent == &(clist->head)) {
				pCurrent = pCurrent->next;
		}
		index++;
	}

	//��ӡ
	Print_CircleLinkList(clist, MyPrint);

	//�ͷ������ڴ�
	FreeSpace_CircleLinkList(clist);


	system("pause");
	return EXIT_SUCCESS;
}