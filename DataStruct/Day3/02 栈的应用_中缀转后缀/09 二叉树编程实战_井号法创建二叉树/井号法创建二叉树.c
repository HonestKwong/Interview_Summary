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
	//��ӡ������
	Recursion(root->lchild);
	//��ӡ������
	Recursion(root->rchild);

}

BinaryNode* CreateBinaryTree() {
	rewind(stdin);     //C11֮��
	//fflush(stdin);   //C11֮ǰ
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
	//������
	BinaryNode* root = CreateBinaryTree();
	//��ӡ��
	Recursion(root);
	printf("\n");


	system("pause");
	return EXIT_SUCCESS;
}