#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�������ڵ�
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root) {
	if (root == NULL)
		return;
	//�ȷ��ʸ��ڵ�
	printf("%c", root->ch);

	//�ٱ���������
	Recursion(root->lchild);

	//�ٱ���������
	Recursion(root->rchild);
}

void CreateBinaryTree() {
	//�����ڵ�
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	//�����ڵ��ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;


	//�ݹ����
	Recursion(&node1);
	printf("\n");
}

int main()
{

	CreateBinaryTree();


	system("pause");
	return EXIT_SUCCESS;
}