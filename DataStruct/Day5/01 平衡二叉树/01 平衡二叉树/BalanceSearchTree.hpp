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
	//删除
	void remove(const T& val);
	void removeWhenNoChild(BinaryNode<T>* delNode);
	void removeWhenOnlySingleChild(BinaryNode<T>* delNode);
	void removeWhenDoubleChild(BinaryNode<T>* delNode);

	//寻找最大值节点
	BinaryNode<T>* getMaxNode(BinaryNode<T>* root);

	//拷贝树
	BinaryNode<T>* copyTree(BinaryNode<T>* root, BinaryNode<T>* parent);
	//释放树
	void freeTree(BinaryNode<T>* root);

public:
	//平衡二叉树的根节点
	BinaryNode<T>* pRoot;
	//节点的个数
	int mSize;

};

template <class T>
BalanceSearchTree<T>::BalanceSearchTree() {
	pRoot = NULL;
	mSize = 0; 
}
template <class T>
BalanceSearchTree<T>::BalanceSearchTree(const BalanceSearchTree &bst) {
	mSize = bst.mSize;
	//拷贝二叉树
	BinaryNode<T>* newroot = copyTree(bst.pRoot, NULL);
	//更新当前树的pRoot  
	pRoot = newroot;
}

template <class T>
BinaryNode<T>* BalanceSearchTree<T>::copyTree(BinaryNode<T>* root, BinaryNode<T>* parent) {
	if (root == NULL) return NULL;

	BinaryNode<T>* newnode = new BinaryNode<T>;
	newnode->mData = root->mData;
	//先拷贝左子树
	BinaryNode<T>* lchild = copyTree(root->pLchild, newnode);
	//拷贝右子树
	BinaryNode<T>* rchild = copyTree(root->pRchild, newnode);
	//最后拷贝当前节点
	newnode->pLchild = lchild;
	newnode->pRchild = rchild;
	newnode->pParent = parent;

	return newnode;
}

template <class T>
BalanceSearchTree<T>& BalanceSearchTree<T>:: operator=(const BalanceSearchTree &bst) {
	//1.先释放
	if (pRoot != NULL) {
		freeTree(pRoot);
	}

	//2.拷贝二叉树
	mSize = bst.mSize;
	BinaryNode<T>* newroot = copyTree(bst.pRoot, NULL);
	//更新当前树的pRoot  指针
	pRoot = newroot;
	return *this;

}
template <class T>
BalanceSearchTree<T>::~BalanceSearchTree() {
	freeTree(pRoot);
	mSize = 0;
	pRoot = NULL;
}

//遍历函数
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreach(_Func callback) {
	foreachRecursion(pRoot, callback);
	
}

//递归遍历函数
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreachRecursion(BinaryNode<T>* root, _Func callback) {
	if (root == NULL) return;
	foreachRecursion(root->pLchild, callback);
	callback(root->mData);
	foreachRecursion(root->pRchild, callback);
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

//删除
template <class T>
void BalanceSearchTree<T>::remove(const T& val) {
	//查找值为val的节点
	BinaryNode<T>* delNode = searchNode(val);
	if (delNode == NULL) {
		return;
	}
	if (!delNode->pLchild && !delNode->pRchild) {
		removeWhenNoChild(delNode);
	}
	else if (delNode->pLchild && delNode->pRchild) {
		removeWhenDoubleChild(delNode);
	}
	else {
		removeWhenOnlySingleChild(delNode);
	}
	mSize--;
}

template <class T>
void BalanceSearchTree<T>::removeWhenNoChild(BinaryNode<T>* delNode) {
	if (NULL == delNode)
		return;
	//1. 判断删除的节点是否为根节点
	if (pRoot == delNode) {
		pRoot = NULL;
	}
	else {
		if (delNode->pParent->pLchild == delNode) {
			delNode->pLchild->pLchild = NULL;
		}
		else
			delNode->pParent->pRchild = NULL;
	}

	//释放删除节点的内存
	delete delNode;
	delNode = NULL;
	--mSize;
}

template <class T>
void BalanceSearchTree<T>::removeWhenOnlySingleChild(BinaryNode<T>* delNode) {
	if (NULL == delNode) return;
	//1.删除的节点是根节点
	BinaryNode<T>* child = (delNode->pLchild != NULL ? delNode->pLchild : delNode->pRchild);
	if (pRoot == delNode)
	{
		pRoot = child;
	}
	else if(delNode->pParent->pLchild == delNode){
		delNode->pParent->pLchild = child;
	}
	else {
		delNode->pParent->pRchild = child;
	}
	child->pParent = delNode->pParent;
	//释放当前节点的内存
	delete delNode;
	delNode = NULL;
	--mSize;
}

template <class T>
void BalanceSearchTree<T>::removeWhenDoubleChild(BinaryNode<T>* delNode) {
	if (delNode == NULL) return;

		//获得删除节点的左子树中最大值的节点
	BinaryNode<T>* max = getMaxNode(delNode->pLchild);
	if (delNode == pRoot) {
		//最大的节点是删除节点的左子树
		if (max == delNode->pLchild) {
			max->pRchild = delNode->pRchild;
//			delNode->mData = max->mData;
//			delNode->pLchild = NULL;
//			delete max;
// 			max = NULL;
		}
		else {
			//最大值节点的父节点的右子树指向最大值节点的左节点
			max->pParent->pRchild = max->pLchild;
			if (max->pLchild != NULL)
				max->pLchild->pParent = max->pParent;
			//最大值节点指向删除节点的左右子树
			max->pLchild = delNode->pLchild;
			max->pRchild = delNode->pRchild;

			//删除节点的父节点指向最大值节点

		}
		max->pLchild->pParent = max;
		max->pRchild->pParent = max;
		max->pParent = delNode->pParent;
		pRoot = max;
	}
	else {
		//获得删除节点的左子树中最大值的节点
		//最大的节点是删除节点的左子树
		if (max == delNode->pLchild) {
			max->pRchild = delNode->pRchild;
			if (delNode->pParent->pLchild == delNode) {
				delNode->pParent->pLchild = max;
			}
			else {
				delNode->pParent->pRchild = max;
			}
//			delNode->mData = max->mData;
//			delNode->pLchild = NULL;
//			delete max;
// 			max = NULL;
		}
		else {
			//最大值节点的父节点指向最大值节点的左节点
			max->pParent->pRchild = max->pLchild;
			if (max->pLchild != NULL)
				max->pLchild->pParent = max->pParent;
			//最大值节点指向删除节点的左右子树
			max->pLchild = delNode->pLchild;
			max->pRchild = delNode->pRchild;

			//删除节点的父节点指向最大值节点
			if(delNode->pParent->pLchild == delNode)  
				delNode->pParent->pLchild = max;
			else
				delNode->pParent->pRchild = max;
		}
		max->pLchild->pParent = max;
		max->pRchild->pParent = max;
		max->pParent = delNode->pParent;
	}
	delete delNode;
	delNode = NULL;
}


template <class T>
BinaryNode<T>* BalanceSearchTree<T>::getMaxNode(BinaryNode<T>* root) {
	if (NULL == root)
		return NULL;
	BinaryNode<T>* pMax = NULL;
	BinaryNode<T>* pCurrent = root;
	while (pCurrent != NULL) {
		pMax = pCurrent;
		pCurrent = pCurrent->pRchild;
	}

	return pMax;
}
//查找节点
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

	//释放树
template <class T>
void BalanceSearchTree<T>::freeTree(BinaryNode<T>* root) {
	if (root == NULL) return;
	freeTree(root->pLchild);
	freeTree(root->pRchild);
	delete root;
	root = NULL;   //避免悬空指针

}


