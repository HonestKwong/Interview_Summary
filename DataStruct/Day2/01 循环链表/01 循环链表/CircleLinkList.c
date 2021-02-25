#include "CircleLinkList.h"

//初始化函数
CircleLinkList* Init_CircleLinkList() {
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}

//插入函数
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data) {
	if (clist == NULL || data == NULL) return;
	if (pos < 0 || pos > clist->size) pos = clist->size;

	//根据位置查找节点
	//辅助指针变量
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//新数据如链表
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
	
}

 //获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist) {
	return clist->head.next;
}

//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos) {
	if (clist == NULL) return;
	if (pos < 0 || pos >= clist->size) return;

	//根据pos 找节点
	//辅助指针变量
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) {
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	pPrev->next = pCurrent->next;
	clist->size--;
}

//根据值去删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare) {
	if (clist == NULL || data == NULL) return;
	
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = clist->head.next;
	
	for (int i = 0; i < clist->size; i++) {
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) {
			pPrev->next = pCurrent->next;
			clist->size--;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next; // pPrev->next 也可以
	}
	
	return;

}

//获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist) {
	return clist->size;
}

//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist) {
	if (clist->size == 0)
		return CIRCLELINKLIST_FALSE;
	return CIRCLELINKLIST_TRUE;
}

//查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare) {
	if (clist == NULL || data == NULL) return -1;
	
	CircleLinkNode* pCurrent = clist->head.next;
	int flag = -1;
	for (int i = 0; i < clist->size; i++) {
		if (compare(pCurrent, data) == CIRCLELINKLIST_TRUE) {
			flag = i;
			break;
		}
		pCurrent = pCurrent->next;
	}
	return flag;

}

//打印节点
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print) {
	if (clist == NULL) return;
	
	CircleLinkNode* pCurrent = clist->head.next;
	for (int i = 0; i < clist->size; i++) {
		if (pCurrent == &(clist->head)) {
			pCurrent = pCurrent->next;
			printf("--------------\n");
		}
		print(pCurrent);
		pCurrent = pCurrent->next;
	}

}

//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist) {
	if (clist == NULL) return;
	free(clist);
}

