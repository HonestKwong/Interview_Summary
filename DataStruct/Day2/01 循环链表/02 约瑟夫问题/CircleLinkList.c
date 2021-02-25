#include "CircleLinkList.h"

//��ʼ������
CircleLinkList* Init_CircleLinkList() {
	CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next = &(clist->head);
	clist->size = 0;
	return clist;
}

//���뺯��
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data) {
	if (clist == NULL || data == NULL) return;
	if (pos < 0 || pos > clist->size) pos = clist->size;

	//����λ�ò��ҽڵ�
	//����ָ�����
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//������������
	data->next = pCurrent->next;
	pCurrent->next = data;

	clist->size++;
	
}

 //��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist) {
	return clist->head.next;
}

//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos) {
	if (clist == NULL) return;
	if (pos < 0 || pos >= clist->size) return;

	//����pos �ҽڵ�
	//����ָ�����
	CircleLinkNode* pPrev = &(clist->head);
	CircleLinkNode* pCurrent = &(clist->head);
	for (int i = 0; i < pos; i++) {
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	pPrev->next = pCurrent->next;
	clist->size--;
}

//����ֵȥɾ��
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
		pCurrent = pCurrent->next; // pPrev->next Ҳ����
	}
	
	return;

}

//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist) {
	return clist->size;
}

//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist) {
	if (clist->size == 0)
		return CIRCLELINKLIST_FALSE;
	return CIRCLELINKLIST_TRUE;
}

//����
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

//��ӡ�ڵ�
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

//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist) {
	if (clist == NULL) return;
	free(clist);
}

