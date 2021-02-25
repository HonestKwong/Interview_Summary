#include "LinkStack.h"
//��ʼ������
LinkStack* Init_LinkStack() {
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->size = 0;
	stack->head.next = NULL;

	return stack;
}

//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data) {
	if (stack == NULL || stack == NULL) return;
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}

//��ջ
void Pop_LinkStack(LinkStack* stack) {
	if (stack == NULL || stack->size == 0) return;
	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;
	stack->size--;
}

//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack) {
	if (stack == NULL || stack->size == 0) return;
	return stack->head.next;

}

//����ջԪ�ظ���
int Size_LinkStack(LinkStack* stack) {
	if (stack == NULL) return -1;
	return stack->size;
}

//���ջ
void Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) 
		return;
	stack->head.next = NULL;
	stack->size = 0;
}

//����ջ
void FreeSpace_LineStack(LinkStack* stack) {
	if (stack == NULL) return;
	free(stack);
}
