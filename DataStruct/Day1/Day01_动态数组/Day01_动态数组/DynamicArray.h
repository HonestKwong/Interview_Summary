#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//��̬�����ڴ棬 ���Խ�������ݵ��ڴ�ŵ��ǣ� ����
//��̬���� ���5��Ԫ�� �����ڴ� �������� �ͷ��ڴ�6 ������߸���capacity
//����capacity ��ʾ�ҵ�����ڴ�ؼ�һ�����Դ�Ŷ���Ԫ��
//size ��� ��¼��ǰ�����о����Ԫ�ظ���

typedef struct DYNAMICARRAY {
	int* pAddr; //������ݵĵ�ַ
	int size;  //��ǰ�ж��ٸ�Ԫ��
	int capacity; // ������ ��������ǰ��������ɶ���Ԫ��
}Dynamic_Array;

//дһϵ�е���ض�DYNAMICARRAY�ṹͼ�����ĺ���
//��ʼ��
Dynamic_Array* Init_Array();
//����
void Push_Back_Array(Dynamic_Array* arr, int value);
//ɾ��
void Remove_Array(Dynamic_Array* arr, int pos);
//����ֵɾ��
void RemovebyValue_Array(Dynamic_Array* arr, int value);
//����
int Find_Array(Dynamic_Array* arr, int value);
//��ӡ
void Print_Array(Dynamic_Array* arr);
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array* arr);

//�������
void Clear_Array(Dynamic_Array* arr);


//��ö�̬��������
int Capacity_Array(Dynamic_Array* arr);

//��ö�̬���ݵ�ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr);

//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos);


#endif
