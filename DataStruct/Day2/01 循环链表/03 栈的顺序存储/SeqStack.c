#include "SeqStack.h"

//��ʼ��ջ
SeqStack* Init_SeqStack() {
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return stack;
}

//��ջ
void Push_SeqStack(SeqStack* stack, void* data) {
	if (stack == NULL || data == NULL || stack->size == MAX_SIZE) return;

	stack->data[stack->size] = data;
	stack->size++;
}

//����ջ��Ԫ��
void* Top_SeqStack(SeqStack* stack) {
	if (stack == NULL || stack->size == 0) return NULL;

	return stack->data[stack->size - 1];
}

//��ջ
void Pop_SeqStack(SeqStack* stack) {
	if (stack == NULL || stack->size == NULL)
		return;
	stack->data[stack->size - 1] = NULL;
	stack->size--;
}

//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack* stack) {
	if (stack == NULL)
		return -1;
	if (stack->size == 0)
		return SEQSTACK_TRUE;
	else return SEQSTACK_FALSE;
}
//����ջ��Ԫ�صĸ���
int Size_SeqStack(SeqStack* stack) {
	if (stack == NULL) return -1;
	else
		return stack->size;
}


//���ջ
void Clear_SeqStack(SeqStack* stack) {
	if (stack == NULL)
		return;
	for (int i = 0; i < stack->size; i++)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
}

//����
void FreeSpace_SeqStack(SeqStack* stack) {
	if (stack!= NULL)
		return;
	free(stack);
}


