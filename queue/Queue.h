#ifndef QUEUE_H_
#define QUEUE_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _queue {
	int *queue;					/* ť ������� ������ */
	int size;						/* ť ������� ũ�� */
	int front;						/* ������ ��� ���� �ɹ� */
	int rear;						/* ������ �Է� ���� �ɹ� */
} queue_t;

/* ť ���� �� �ʱ�ȭ �Լ� */
bool_t createQueue(queue_t *qp, int size);
/* ť�� ������ ��� �ִ°� */
bool_t isQueueEmpty(const queue_t *qp);
/* ť�� �� �� �ִ°� �˻� */
bool_t isQueueFull(const queue_t *qp);
/* ť�� ������ �ϳ��� ���� �� */
bool_t enqueue(queue_t *qp, int enqueData);
/* ť���� ������ �ϳ��� ���� */
bool_t dequeue(queue_t *qp, int *dequeData);
/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void printQueue(const queue_t *qp);
void destroyQueue(queue_t *qp);						/* ť �Ҹ� �Լ� */

#endif /* QUEUE_H_ */
