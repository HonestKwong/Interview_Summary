#pragma once

//����������Ľڵ�
template <class T>
struct BinaryNode
{
	//������
	T mData;
	//�߶�
	int mDepth;
	//ָ����
	BinaryNode<T>* pLchild;
	BinaryNode<T>* pRchild;
	BinaryNode<T>* pParent;
};

template <class T>
class BalanceSearchTree
{
public:
	BalanceSearchTree();
	BalanceSearchTree(const BalanceSearchTree &bst);
	BalanceSearchTree& operator=(const BalanceSearchTree &bst);
	~BalanceSearchTree();

	//�жϽڵ��Ƿ����
	BinaryNode<T>* searchNode(const T &val);

	//��������
	template <class _Func>
	void foreach(_Func callback);

	template <class _Func>
	void foreachRecursion(BinaryNode<T>* root, _Func callback);
	//����
	void insert(const T& val);
public:
	//ƽ��������ĸ��ڵ�
	BinaryNode<T>* pRoot;
	//�ڵ�ĸ���
	int mSize;

};

template <class T>
BalanceSearchTree<T>::BalanceSearchTree() {

}
template <class T>
BalanceSearchTree<T>::BalanceSearchTree(const BalanceSearchTree &bst) {

}
template <class T>
BalanceSearchTree<T>& BalanceSearchTree<T>:: operator=(const BalanceSearchTree &bst) {

}
template <class T>
BalanceSearchTree<T>::~BalanceSearchTree() {

}

//��������
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreach(_Func callback) {
	this->pRoot = NULL;
	this->mSize = 0;
	

}

//�ݹ��������
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreachRecursion(BinaryNode<T>* root, _Func callback) {
	if (root == NULL) return;
	foreachRecursion(root->pLchild, callback);
	callback(root->mData);
	foreachRecusion(root->pRchild, callback);
}

//����
template <class T>
void BalanceSearchTree<T>::insert(const T& val) {
	//1.���жϽڵ��Ƿ����
	if (searchNode(val) != NULL) return;
	//2.�����������ڵ�
	BinaryNode<T>* newnode = new BinaryNode<T>;
	newnode->mData = val;
	newnode->mDepth = 0;
	newnode->pLchild = NULL;
	newnode->pRchild = NULL;
	newnode->pParent = NULL;
	
	//3.�ж��Ƿ�Ϊ����
	if (pRoot == NULL) {
		pRoot = newnode;
		mSize++; 
		return;
	}
	//4.�Ҳ���λ��
	BinaryNode<T>* pCurrent = pRoot;
	BinaryNode<T>* pPrev = pRoot;
	
	while (pCurrent != NULL) {
		pPrev = pCurrent;
		if (pCurrent->mData > val) {
			pCurrent = pCurrent->pLchild;
			if (pCurrent == NULL) {
				pPrev->pLchild = newnode;
			}
		}
		else if (pCurrent->mData < val) {
			pCurrent = pCurrent->pRchild;
			if (pCurrent == NULL) {
				pPrev->pRchild = newnode;
			}
		}
	}

	newnode->pParent = pPrev;
	mSize++; 

}

template <class T>
BinaryNode<T>* BalanceSearchTree<T>::searchNode(const T &val) {
	BinaryNode<T>* pCurrent = pRoot;
	while (pCurrent != NULL) {
		if (val == pCurrent->mData) return pCurrent;
		else if (val < pCurrent->mData) pCurrent = pCurrent->pLchild;
		else if (val > pCurrent->mData) pCurrent = pCurrent->pRchild;
	}
	return pCurrent;   //�˳�ѭ�����ؿ�
}


