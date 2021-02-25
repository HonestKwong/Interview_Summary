#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE 1

//���������
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

typedef struct BITREESTACKNODE {
	LinkNode node;
	BinaryNode* root;
	int flag;
}BiTreeStackNode;

//����ջ�еĽڵ�
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, int flag) {
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;
	return newnode;
}

//�������ķǵݹ����
void NonRecursion(BinaryNode* root) {
	//����ջ
	LinkStack* stack = Init_LinkStack();
	Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));
	while (Size_LinkStack(stack) > 0) {
		//�ȵ���ջ��Ԫ��
		BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		//�жϵ����Ľڵ��Ƿ�Ϊ��
		if (node->root == NULL) {
			continue;
		}
		if (node->flag == MY_TRUE)
			printf("%c", node->root->ch);

		else if (node->flag == MY_FALSE) {
			//��ǰ�ڵ���ҽڵ���ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->rchild, MY_FALSE));
			//��ǰ�ڵ����ڵ���ջ
			Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node->root->lchild, MY_FALSE));
			//��ǰ�ڵ���ջ
			node->flag = MY_TRUE;
			Push_LinkStack(stack, node);
		}
	}
}

void Recursion(BinaryNode* root) {
	if (root == NULL) return;
	printf("%c", root->ch);
	//��ӡ������
	Recursion(root->lchild);
	//��ӡ������
	Recursion(root->rchild);

}

void CreateBinaryTree(){
	//�������
	BinaryNode node1 = {'A',NULL,NULL};
	BinaryNode node2 = {'B',NULL,NULL};
	BinaryNode node3 = {'C',NULL,NULL};
	BinaryNode node4 = {'D',NULL,NULL};
	BinaryNode node5 = {'E',NULL,NULL};
	BinaryNode node6 = {'F',NULL,NULL};
	BinaryNode node7 = {'G',NULL,NULL};
	BinaryNode node8 = {'H',NULL,NULL};
	
	//��������ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	
	//�������ķǵݹ����
	NonRecursion(&node1);
	printf("\n");
	Recursion(&node1);
	printf("\n");
	
}

int main()
{

	CreateBinaryTree();


	system("pause");
	return EXIT_SUCCESS;
}