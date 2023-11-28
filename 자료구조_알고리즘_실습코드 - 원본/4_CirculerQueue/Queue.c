#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*-------------------------------------------------------------
Function name	: createQueue() - 원형 큐 생성 및 초기화 함수
Parameters		: qp - 큐 구조체의 주소
				  size - 큐의 크기
Returns		: 없음
--------------------------------------------------------------*/
bool_t createQueue(queue_t *qp, int size) {

	/* TO DO */

	return TRUE;
}

/* -------------------------------------------------------------
Function name	: isQueueEmpty() - 큐가 완전히 비어 있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns		: 완전히 비어 있으면 TRUE
				  비어 있지 않으면 FALSE
--------------------------------------------------------------*/
bool_t isQueueEmpty(const queue_t *qp) {

	/* TO DO */

	return FALSE;
}

/* -------------------------------------------------------------
Function name	: isQueueFull() - 큐가 꽉 차 있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns		: 꽉 차 있으면 TRUE
				  아니면 FALSE 리턴
--------------------------------------------------------------*/
bool_t isQueueFull(const queue_t *qp) {

	/* TO DO */

	return FALSE;
}

/* -------------------------------------------------------------
Function name	: enqueue() - 큐에 데이터 하나를 저장함
Parameters		: qp - 큐 구조체의 주소
				  enqueData - 큐에 저장할 데이터
Returns		: 성공적으로 저장하면 TRUE
				  실패하면 FALSE
--------------------------------------------------------------*/
bool_t enqueue(queue_t *qp, int enqueData) {

	/* TO DO */

	return TRUE;
}

/* -------------------------------------------------------------
Function name	: dequeue() - 큐에서 데이터 하나를 꺼냄
Parameters		: qp - 큐 구조체의 주소
				  dequeData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns		: 성공적으로 꺼내면 TRUE
				  실패하면 FALSE 리턴
--------------------------------------------------------------*/
bool_t dequeue(queue_t *qp, int *dequeData) {

	/* TO DO */

	return TRUE;
}

/* -------------------------------------------------------------
Function name	: printQueue() - 큐 내의 모든 데이터를 출력 함
Parameters		: qp - 큐 구조체의 주소
Returns		: 없음
--------------------------------------------------------------*/
void printQueue(const queue_t *qp) {

	/* TO DO */

}

/* -------------------------------------------------------------
Function name	: destroyQueue() - 큐 소멸 함수
Parameters		: qp - 큐 구조체의 주소
Returns		: 없음
--------------------------------------------------------------*/
void destroyQueue(queue_t * qp) {

	/* TO DO */

}


