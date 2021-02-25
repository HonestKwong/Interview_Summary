#ifndef CIRCLELINKLIST
#define CIRCLELINKLIST

#include <stdio.h>
#include <stdlib.h>

//链表小节点
typedef struct CIRCLELINKNODE {
	struct CIRCLELINKNODE* next;  //需要添加struct关键字
}CircleLinkNode;

//链表的结构体
typedef struct CIRCLELINKLIST {
	CircleLinkNode head;    //这里链表不需要使用指针
	int size;
}CircleLinkList;

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

//比较回调
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);

//打印回调
typedef void(*PRINTNODE)(CircleLinkNode*);


//编写针对链表结构体操作的API操作

//初始化函数
CircleLinkList* Init_CircleLinkList();

//插入函数
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

 //获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist, int pos);

//根据值去删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist);

//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist);

//查找
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//打印节点
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist);

#endif // CIRCLELINKLIST
