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
	//ɾ��
	void remove(const T& val);
	void removeWhenNoChild(BinaryNode<T>* delNode);
	void removeWhenOnlySingleChild(BinaryNode<T>* delNode);
	void removeWhenDoubleChild(BinaryNode<T>* delNode);

	//Ѱ�����ֵ�ڵ�
	BinaryNode<T>* getMaxNode(BinaryNode<T>* root);

	//������
	BinaryNode<T>* copyTree(BinaryNode<T>* root, BinaryNode<T>* parent);
	//�ͷ���
	void freeTree(BinaryNode<T>* root);

public:
	//ƽ��������ĸ��ڵ�
	BinaryNode<T>* pRoot;
	//�ڵ�ĸ���
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
	//����������
	BinaryNode<T>* newroot = copyTree(bst.pRoot, NULL);
	//���µ�ǰ����pRoot  
	pRoot = newroot;
}

template <class T>
BinaryNode<T>* BalanceSearchTree<T>::copyTree(BinaryNode<T>* root, BinaryNode<T>* parent) {
	if (root == NULL) return NULL;

	BinaryNode<T>* newnode = new BinaryNode<T>;
	newnode->mData = root->mData;
	//�ȿ���������
	BinaryNode<T>* lchild = copyTree(root->pLchild, newnode);
	//����������
	BinaryNode<T>* rchild = copyTree(root->pRchild, newnode);
	//��󿽱���ǰ�ڵ�
	newnode->pLchild = lchild;
	newnode->pRchild = rchild;
	newnode->pParent = parent;

	return newnode;
}

template <class T>
BalanceSearchTree<T>& BalanceSearchTree<T>:: operator=(const BalanceSearchTree &bst) {
	//1.���ͷ�
	if (pRoot != NULL) {
		freeTree(pRoot);
	}

	//2.����������
	mSize = bst.mSize;
	BinaryNode<T>* newroot = copyTree(bst.pRoot, NULL);
	//���µ�ǰ����pRoot  ָ��
	pRoot = newroot;
	return *this;

}
template <class T>
BalanceSearchTree<T>::~BalanceSearchTree() {
	freeTree(pRoot);
	mSize = 0;
	pRoot = NULL;
}

//��������
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreach(_Func callback) {
	foreachRecursion(pRoot, callback);
	
}

//�ݹ��������
template <class T>
template <class _Func>
void BalanceSearchTree<T>::foreachRecursion(BinaryNode<T>* root, _Func callback) {
	if (root == NULL) return;
	foreachRecursion(root->pLchild, callback);
	callback(root->mData);
	foreachRecursion(root->pRchild, callback);
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

//ɾ��
template <class T>
void BalanceSearchTree<T>::remove(const T& val) {
	//����ֵΪval�Ľڵ�
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
	//1. �ж�ɾ���Ľڵ��Ƿ�Ϊ���ڵ�
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

	//�ͷ�ɾ���ڵ���ڴ�
	delete delNode;
	delNode = NULL;
	--mSize;
}

template <class T>
void BalanceSearchTree<T>::removeWhenOnlySingleChild(BinaryNode<T>* delNode) {
	if (NULL == delNode) return;
	//1.ɾ���Ľڵ��Ǹ��ڵ�
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
	//�ͷŵ�ǰ�ڵ���ڴ�
	delete delNode;
	delNode = NULL;
	--mSize;
}

template <class T>
void BalanceSearchTree<T>::removeWhenDoubleChild(BinaryNode<T>* delNode) {
	if (delNode == NULL) return;

		//���ɾ���ڵ�������������ֵ�Ľڵ�
	BinaryNode<T>* max = getMaxNode(delNode->pLchild);
	if (delNode == pRoot) {
		//���Ľڵ���ɾ���ڵ��������
		if (max == delNode->pLchild) {
			max->pRchild = delNode->pRchild;
//			delNode->mData = max->mData;
//			delNode->pLchild = NULL;
//			delete max;
// 			max = NULL;
		}
		else {
			//���ֵ�ڵ�ĸ��ڵ��������ָ�����ֵ�ڵ����ڵ�
			max->pParent->pRchild = max->pLchild;
			if (max->pLchild != NULL)
				max->pLchild->pParent = max->pParent;
			//���ֵ�ڵ�ָ��ɾ���ڵ����������
			max->pLchild = delNode->pLchild;
			max->pRchild = delNode->pRchild;

			//ɾ���ڵ�ĸ��ڵ�ָ�����ֵ�ڵ�

		}
		max->pLchild->pParent = max;
		max->pRchild->pParent = max;
		max->pParent = delNode->pParent;
		pRoot = max;
	}
	else {
		//���ɾ���ڵ�������������ֵ�Ľڵ�
		//���Ľڵ���ɾ���ڵ��������
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
			//���ֵ�ڵ�ĸ��ڵ�ָ�����ֵ�ڵ����ڵ�
			max->pParent->pRchild = max->pLchild;
			if (max->pLchild != NULL)
				max->pLchild->pParent = max->pParent;
			//���ֵ�ڵ�ָ��ɾ���ڵ����������
			max->pLchild = delNode->pLchild;
			max->pRchild = delNode->pRchild;

			//ɾ���ڵ�ĸ��ڵ�ָ�����ֵ�ڵ�
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
//���ҽڵ�
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

	//�ͷ���
template <class T>
void BalanceSearchTree<T>::freeTree(BinaryNode<T>* root) {
	if (root == NULL) return;
	freeTree(root->pLchild);
	freeTree(root->pRchild);
	delete root;
	root = NULL;   //��������ָ��

}


