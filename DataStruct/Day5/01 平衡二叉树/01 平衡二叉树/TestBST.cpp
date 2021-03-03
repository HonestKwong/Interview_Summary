#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "BalanceSearchTree.hpp"

void test() {
	BalanceSearchTree<int> bst;
	bst.insert(80);
	bst.insert(20);
	bst.insert(60);
	bst.insert(50);
	bst.insert(90); // 2
	bst.insert(10);
	bst.insert(5);

	bst.foreach([] (int val){ cout << val << " "; });
	cout << endl;

	BalanceSearchTree<int> newbst(bst);
	newbst.foreach([](int val) { cout << val << " "; });
	cout << endl;

	BalanceSearchTree<int> bst2 = bst;
	newbst.foreach([](int val) { cout << val << " "; });
	cout << endl;

	cout << bst.searchNode(5)->pParent->mData << endl;
}
void test01() {
	BalanceSearchTree<int> bst;
	bst.insert(80);
	bst.insert(20);
	bst.insert(60);
	bst.insert(50);
	bst.insert(90); // 2
	bst.insert(10);
	bst.insert(5);

	bst.foreach([] (int val){ cout << val << " "; });
	cout << endl;

	BalanceSearchTree<int> newbst(bst);
	newbst.foreach([](int val) { cout << val << " "; });
	cout << endl;

	bst.remove(80);
	bst.foreach([](int val) { cout << val << " "; });
	cout << endl;

	cout << bst.pRoot->pLchild->mData << endl;
}
int main()
{
	//test();
	test01();


	system("pause");
	return EXIT_SUCCESS;
}