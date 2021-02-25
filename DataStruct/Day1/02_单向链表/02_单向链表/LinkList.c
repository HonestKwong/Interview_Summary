#include "LinkList.h"



// 初始化链表
LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	//头节点不保存数据信息
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}
//指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* data) {
	if (list == NULL) {
		return;
	}

	if (data == NULL) {
		return;
	}
	
	//友好的处理方式, pos越界
	if (pos < 0 || pos > list->size) {
		pos = list->size;
	}

	//创建新的节点
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//找节点
	//辅助指针变量
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	//新节点入链表
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//修稿链表大小
	list->size++;
}
//删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos) {
	//判断传入参数是否合法
	if (list == NULL)
		return;

	//判断传入位置是否越界
	if (pos<0 || pos > list->size) {
		return;
	}
	
	//找到所在位置
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos - 1; i++) {
		pCurrent = pCurrent->next;
	}
	
	//删除缓存的节点
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	//释放删除的节点
	free(pDel);

	//维护链表大小
	list->size--;
}
//获取链表长度
int Size_LinkList(LinkList* list) {
	if (list == NULL)
		return -1;
	return list->size;
}
//查找
int Find_LinkList(LinkList* list, void* data) {
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	//遍历查找
	LinkNode* pCurrent = list->head->next;
	int i = 0;
	for (i = 0; pCurrent != NULL; i++, pCurrent = pCurrent->next) {
		if (pCurrent->data == data)
			break;
	}
	return i;

	 
}
//打印链表节点
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
	if (list == NULL) return;
	//辅助指针变量 
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL) {
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//返回第一个结点
void* Front_LinkList(LinkList* list) {
	if (list == NULL) return NULL;
	return list->head->next->data;
}
//释放链表内存
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL) return;
	//辅助指针变量
	LinkNode* pCurrent = list->head->next;
	LinkNode* tmp;
	if (pCurrent != NULL) {
		tmp = pCurrent;
		pCurrent = pCurrent->next;
		free(tmp);
	}
	//释放链表内存
	free(list->head);
	free(list);
}


