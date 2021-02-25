#include "LinkStack.h"
//初始化函数
LinkStack* Init_LinkStack() {
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->size = 0;
	stack->head.next = NULL;

	return stack;
}

//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data) {
	if (stack == NULL || stack == NULL) return;
	data->next = stack->head.next;
	stack->head.next = data;
	stack->size++;
}

//出栈
void Pop_LinkStack(LinkStack* stack) {
	if (stack == NULL || stack->size == 0) return;
	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;
	stack->size--;
}

//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack) {
	if (stack == NULL || stack->size == 0) return;
	return stack->head.next;

}

//返回栈元素个数
int Size_LinkStack(LinkStack* stack) {
	if (stack == NULL) return -1;
	return stack->size;
}

//清空栈
void Clear_LinkStack(LinkStack* stack) {
	if (stack == NULL) 
		return;
	stack->head.next = NULL;
	stack->size = 0;
}

//销毁栈
void FreeSpace_LineStack(LinkStack* stack) {
	if (stack == NULL) return;
	free(stack);
}
