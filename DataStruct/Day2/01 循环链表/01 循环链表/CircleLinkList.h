#ifndef CIRCLELINKLIST
#define CIRCLELINKLIST

#include <stdio.h>
#include <stdlib.h>

//����С�ڵ�
typedef struct CIRCLELINKNODE {
	struct CIRCLELINKNODE* next;  //��Ҫ���struct�ؼ���
}CircleLinkNode;

//����Ľṹ��
typedef struct CIRCLELINKLIST {
	CircleLinkNode head;    //����������Ҫʹ��ָ��
	int size;
}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//�Ƚϻص�
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

//��ӡ�ص�
typedef void(*PRINTNODE)(CircleLinkNode*);


//��д�������ṹ�������API����

//��ʼ������
CircleLinkList* Init_CircleLinkList();

//���뺯��
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

 //��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);

//����ֵȥɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist);

//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist);

//����
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//��ӡ�ڵ�
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist);

#endif // CIRCLELINKLIST
