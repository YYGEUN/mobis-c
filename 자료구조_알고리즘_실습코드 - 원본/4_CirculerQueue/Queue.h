#ifndef QUEUE_H_
#define QUEUE_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _queue {
	int *queue;					/* 큐 저장공간 포인터 */
	int size;						/* 큐 저장공간 크기 */
	int front;						/* 데이터 출력 참조 맴버 */
	int rear;						/* 데이터 입력 참조 맴버 */
} queue_t;

/* 큐 생성 및 초기화 함수 */
bool_t createQueue(queue_t *qp, int size);
/* 큐가 완전히 비어 있는가 */
bool_t isQueueEmpty(const queue_t *qp);
/* 큐가 꽉 차 있는가 검사 */
bool_t isQueueFull(const queue_t *qp);
/* 큐에 데이터 하나를 저장 함 */
bool_t enqueue(queue_t *qp, int enqueData);
/* 큐에서 데이터 하나를 꺼냄 */
bool_t dequeue(queue_t *qp, int *dequeData);
/* 큐 내의 모든 데이터를 출력(dequeue하는 것은 아님) */
void printQueue(const queue_t *qp);
void destroyQueue(queue_t *qp);						/* 큐 소멸 함수 */

#endif /* QUEUE_H_ */
