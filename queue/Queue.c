#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*-------------------------------------------------------------
Function name	: createQueue() - ���� ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns		: ����
--------------------------------------------------------------*/
bool_t createQueue(queue_t* qp, int size) {

	if (qp == NULL) {
		return FALSE;
	}

	qp->queue = (int*)malloc(sizeof(int) * size);
	if (qp->queue == NULL)
	{
		return FALSE;
	}


	qp->rear = 0;
	qp->front = 0;

	return TRUE;
}

/* -------------------------------------------------------------
Function name	: isQueueEmpty() - ť�� ������ ��� �ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns		: ������ ��� ������ TRUE
				  ��� ���� ������ FALSE
--------------------------------------------------------------*/
bool_t isQueueEmpty(const queue_t* qp) {

	if (qp == NULL) {
		return FALSE;
	}

	if (qp->front == qp->rear) {
		return TRUE;
	}

	return FALSE;
}

/* -------------------------------------------------------------
Function name	: isQueueFull() - ť�� �� �� �ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns		: �� �� ������ TRUE
				  �ƴϸ� FALSE ����
--------------------------------------------------------------*/
bool_t isQueueFull(const queue_t* qp) {

	if (qp == NULL) {
		return FALSE;
	}

	if (qp->front == (qp->rear + 1)%qp->size){
		return TRUE;
	}

	return FALSE;
}

/* -------------------------------------------------------------
Function name	: enqueue() - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
				  enqueData - ť�� ������ ������
Returns		: ���������� �����ϸ� TRUE
				  �����ϸ� FALSE
--------------------------------------------------------------*/
bool_t enqueue(queue_t *qp, int enqueData) {

	if (qp == NULL) {
		return FALSE;
	}

	if (isQueueFull(qp) == TRUE)
	{
		return FALSE;
	}

	qp->queue[qp->rear] = enqueData;

	qp->rear = (qp->rear + 1) % qp->size;

	return TRUE;
}

/* -------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns		: ���������� ������ TRUE
				  �����ϸ� FALSE ����
--------------------------------------------------------------*/
bool_t dequeue(queue_t *qp, int *dequeData) {

	if (qp == NULL) {
		return FALSE;
	}

	if (isQueueEmpty(qp) == TRUE)
	{
		return FALSE;
	}

	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;

	return TRUE;
}

/* -------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns		: ����
--------------------------------------------------------------*/
void printQueue(const queue_t *qp) {

	if (qp == NULL) {
		return FALSE;
	}
	for(size_t i = qp->front; i != qp->rear; i=(i+1)%qp->size)
	{
		printf("%d  ", qp->queue[i]);
	}
}

/* -------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns		: ����
--------------------------------------------------------------*/
void destroyQueue(queue_t * qp) {

	if (qp == NULL) {
		return FALSE;
	}

	free(qp->queue);
	qp->queue = NULL;
	qp->size = 0;
	qp->rear = 0;
	qp->front = 0;
}


