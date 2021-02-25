#include "LinkList.h"



// ��ʼ������
LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	//ͷ�ڵ㲻����������Ϣ
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}
//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, void* data) {
	if (list == NULL) {
		return;
	}

	if (data == NULL) {
		return;
	}
	
	//�ѺõĴ���ʽ, posԽ��
	if (pos < 0 || pos > list->size) {
		pos = list->size;
	}

	//�����µĽڵ�
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//�ҽڵ�
	//����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	//�½ڵ�������
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//�޸������С
	list->size++;
}
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos) {
	//�жϴ�������Ƿ�Ϸ�
	if (list == NULL)
		return;

	//�жϴ���λ���Ƿ�Խ��
	if (pos<0 || pos > list->size) {
		return;
	}
	
	//�ҵ�����λ��
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos - 1; i++) {
		pCurrent = pCurrent->next;
	}
	
	//ɾ������Ľڵ�
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	//�ͷ�ɾ���Ľڵ�
	free(pDel);

	//ά�������С
	list->size--;
}
//��ȡ������
int Size_LinkList(LinkList* list) {
	if (list == NULL)
		return -1;
	return list->size;
}
//����
int Find_LinkList(LinkList* list, void* data) {
	if (list == NULL)
		return -1;
	if (data == NULL)
		return -1;
	//��������
	LinkNode* pCurrent = list->head->next;
	int i = 0;
	for (i = 0; pCurrent != NULL; i++, pCurrent = pCurrent->next) {
		if (pCurrent->data == data)
			break;
	}
	return i;

	 
}
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print) {
	if (list == NULL) return;
	//����ָ����� 
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL) {
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}

}
//���ص�һ�����
void* Front_LinkList(LinkList* list) {
	if (list == NULL) return NULL;
	return list->head->next->data;
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list) {
	if (list == NULL) return;
	//����ָ�����
	LinkNode* pCurrent = list->head->next;
	LinkNode* tmp;
	if (pCurrent != NULL) {
		tmp = pCurrent;
		pCurrent = pCurrent->next;
		free(tmp);
	}
	//�ͷ������ڴ�
	free(list->head);
	free(list);
}


