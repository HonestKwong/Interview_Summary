#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root) {
	if (root == NULL) return;
	printf("%c", root->ch);
	//打印左子树
	Recursion(root->lchild);
	//打印右子树
	Recursion(root->rchild);

}

BinaryNode* CreateBinaryTree() {
	rewind(stdin);     //C11之后
	//fflush(stdin);   //C11之前
	char ch;
	scanf("%c", &ch);

	BinaryNode* node;
	if (ch == '#') {
		node = NULL;
	}
	else {

		node = (BinaryNode*)malloc(sizeof(BinaryNode));
		node->ch = ch;
		node->lchild = CreateBinaryTree();
		node->rchild = CreateBinaryTree();
	}

	return node;
}
int main()
{
	//创建树
	BinaryNode* root = CreateBinaryTree();
	//打印树
	Recursion(root);
	printf("\n");


	system("pause");
	return EXIT_SUCCESS;
}