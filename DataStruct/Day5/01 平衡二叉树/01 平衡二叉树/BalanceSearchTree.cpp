#pragma once

//定义二叉树的节点
template <class T>
struct BinaryNode
{
	//数据域
	T mData;
	//高度
	int mDepth;
	//指针域
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

	//判断节点是否存在
	BinaryNode<T>* searchNode(const T &val);

	//遍历函数
	template <class _Func>
	void foreach(_Func callback);

	template <class _Func>
	void foreachRecursion(BinaryNode<T>* root, _Func callback);
	//插入
	void insert(const T& val);
public:
	//平衡二叉树的根节点
	BinaryNode<T>* pRoot;
	//节点的个数
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

//遍历函数
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreach(_Func callback) {
	this->pRoot = NULL;
	this->mSize = 0;
	

}

//递归遍历函数
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreachRecursion(BinaryNode<T>* root, _Func callback) {
	if (root == NULL) return;
	foreachRecursion(root->pLchild, callback);
	callback(root->mData);
	foreachRecusion(root->pRchild, callback);
}

//插入
template <class T>
void BalanceSearchTree<T>::insert(const T& val) {
	//1.先判断节点是否存在
	if (searchNode(val) != NULL) return;
	//2.创建二叉树节点
	BinaryNode<T>* newnode = new BinaryNode<T>;
	newnode->mData = val;
	newnode->mDepth = 0;
	newnode->pLchild = NULL;
	newnode->pRchild = NULL;
	newnode->pParent = NULL;
	
	//3.判断是否为空树
	if (pRoot == NULL) {
		pRoot = newnode;
		mSize++; 
		return;
	}
	//4.找插入位置
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
	return pCurrent;   //退出循环返回空
}


