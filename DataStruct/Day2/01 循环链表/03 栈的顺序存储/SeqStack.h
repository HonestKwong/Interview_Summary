#ifndef SEQSTACK_H
#define SEQSTACK_H
//����ȥģ��ջ��˳��洢
#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

#include <stdio.h>
#include <stdlib.h>

typedef struct SEQSTACK {
	void* data[MAX_SIZE];
	int size;
}SeqStack;

//��ʼ��ջ
SeqStack* Init_SeqStack();

//��ջ
void Push_SeqStack(SeqStack* stack, void* data);

//����ջ��Ԫ��
void* Top_SeqStack(SeqStack* stack);

//��ջ
void Pop_SeqStack(SeqStack* stack);

//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack* stack);
//����ջ��Ԫ�صĸ���
int Size_SeqStack(SeqStack* stack);

//���ջ
void Clear_SeqStack(SeqStack* stack);

//����
void FreeSpace_SeqStack(SeqStack* stack);


#endif // !SEQSTACK_H
