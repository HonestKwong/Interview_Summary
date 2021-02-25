#include "SeqQueue.h"
//��ʼ��
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	queue->size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;
	}
	return queue;
}

//���
void Push_SeqQueue(SeqQueue* queue, void* data) {
	//������߲����ͷ
	if (queue == NULL || data == NULL) return;
	if (queue->size == MAX_SIZE) return;
	queue->data[queue->size] = data;
	queue->size++;

}

//���ض�ͷԪ��
void* Front_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) return;
	if (queue->size == 0) return;
	return queue->data[0];

}

//����
void Pop_SeqQueue(SeqQueue* queue) {
	//��Ҫ�ƶ�Ԫ��
	if (queue == NULL) return;
	if (queue->size == 0) return;
	for (int i = 0; i < queue->size - 1; i++) {
		queue->data[i] = queue->data[i + 1];

	}
	queue->size--;
	queue->data[queue->size] = NULL;


}

//���ض�βԪ��
void* Back_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) return;
	if (queue->size == 0) return;
	return queue->data[queue->size - 1];

}

//���ش�С
int Size_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) return -1;
	return queue->size;

}

//��ն���
void Clear_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) return;
	for (int i = 0; i < queue->size; i++)
		queue->data[i] = NULL;
	queue->size = 0;
}

//���ٶ���
void Free_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) return;
	free(queue);
}


