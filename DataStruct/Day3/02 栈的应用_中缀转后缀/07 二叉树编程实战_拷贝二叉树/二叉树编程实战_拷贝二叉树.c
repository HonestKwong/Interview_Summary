#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recusion(BinaryNode* root) {
	if (root == NULL) return;

	printf("%c", root->ch);
	//遍历左子树
	Recusion(root->lchild);
	//遍历右子树
	Recusion(root->rchild);

}

BinaryNode* CopyBinaryTree(BinaryNode* root) {
	if (root == NULL) return NULL;
	 
	
	//拷贝左子树
	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	//拷贝右子树
	BinaryNode* rchild = CopyBinaryTree(root->rchild);

	//创建节点
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;

}

void FreeSpaceBinaryTree(BinaryNode* root) {
	
	if (root == NULL) {
		return;
	}
	//释放左子树
	FreeSpaceBinaryTree(root->lchild);
	//释放右子树
	FreeSpaceBinaryTree(root->rchild);
	//释放当前
	free(root);
}

//计算树的高度
int CaculateTreDepth(BinaryNode* root){
	
	if(root==NULL){
		return 0;
	}
	
	int depth = 0;
	
	int leftDepth = CaculateTreDepth(root->lchild);
	int rightDepth = CaculateTreDepth(root->rchild);
	depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	
	return depth;
}

void CreateBinaryTree(){
	//创建结点
	BinaryNode node1 = {'A',NULL,NULL};
	BinaryNode node2 = {'B',NULL,NULL};
	BinaryNode node3 = {'C',NULL,NULL};
	BinaryNode node4 = {'D',NULL,NULL};
	BinaryNode node5 = {'E',NULL,NULL};
	BinaryNode node6 = {'F',NULL,NULL};
	BinaryNode node7 = {'G',NULL,NULL};
	BinaryNode node8 = {'H',NULL,NULL};
	
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	Recusion(&node1);
	printf("\n");
	BinaryNode* root = CopyBinaryTree(&node1);
	Recusion(root);

	FreeSpaceBinaryTree(root);
	
}

int main()
{
	CreateBinaryTree();

		

	system("pause");
	return EXIT_SUCCESS;
}
