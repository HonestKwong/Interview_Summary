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
	//创建循环链表
	CircleLinkList* clist = Init_CircleLinkList();
	//链表插入数据  
	MyNum num[M];
	for (int i = 0; i < M; i++) {
		num[i].val = i + 1;
		Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);

	}

	//打印
	Print_CircleLinkList(clist, MyPrint);

	printf("\n");

	//辅助指针
	int index = 1;
	CircleLinkNode* pCurrent = clist->head.next;

	while (Size_CircleLinkList(clist) > 1) {
		if (index == N) {
			MyNum* temNum = (MyNum*)pCurrent;
			printf("%d ", temNum->val);

			//缓存待删除节点的下一个节点
			CircleLinkNode* pNext = pCurrent->next;
			//根据值删除
			RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
			pCurrent = pNext;
			if (pCurrent == &(clist->head)) {
				pCurrent = pCurrent->next;
			}
			index = 1;   
			continue;
		}
		pCurrent = pCurrent->next;     //这里应该先往后移动, 在判断是否为头节点
		if (pCurrent == &(clist->head)) {
				pCurrent = pCurrent->next;
		}
		index++;
	}

	//打印
	Print_CircleLinkList(clist, MyPrint);

	//释放链表内存
	FreeSpace_CircleLinkList(clist);


	system("pause");
	return EXIT_SUCCESS;
}