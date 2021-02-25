#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//二叉树节点
typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void CaculateLeafNum(BinaryNode* root, int* leafNum) {
	if (root == NULL) return;
	if (root->lchild == NULL && root->rchild == NULL)
		(*leafNum)++;
	CaculateLeafNum(root->lchild, leafNum);
	CaculateLeafNum(root->rchild, leafNum);
}

void CreateBinaryTree() {
	//创建节点
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };

	//创建节点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	
	int leafNum = 0;
	CaculateLeafNum(&node1, &leafNum);
	printf("leafNum:  %d", leafNum);

	printf("\n");
}


int main()
{
	CreateBinaryTree();


	system("pause");
	return EXIT_SUCCESS;
}