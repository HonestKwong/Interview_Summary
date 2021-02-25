#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LINKNODE {
	void* data;     //����ָ���κ����͵�����
	struct LINKNODE* next;
}LinkNode;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);

//����ṹ��
typedef struct LINKLIST {
	LinkNode* head;
	int size;
	// ����Ҫ����, û����������
}LinkList;

// ��ʼ������
LinkList* Init_LinkList(); 
//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, void* data); 
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list, int pos);
//��ȡ������
int Size_LinkList(LinkList* list);
//����
int Find_LinkList(LinkList* list, void* data);
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//���ص�һ�����
void* Front_LinkList(LinkList* list);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);

#endif // !LINKLIST_H
