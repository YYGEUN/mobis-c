#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef enum _bool { false = 0, true = 1, FALSE = false, TRUE = true } bool_t;

typedef struct _node {
	struct _node *prev; 
	int data;
	struct _node *next;
} node_t;

typedef struct _list {
	node_t *head;
	node_t *tail;
	int size;
} list_t;

bool_t createList(list_t *lp);				/* ���� ����Ʈ �ʱ�ȭ */
bool_t addFirst(list_t *lp, int data);		/* head node �ڿ� node �߰�(���� ����) */
bool_t addLast(list_t *lp, int data);		/* tail node �տ� node �߰�(���� ����) */
void displayList(list_t *lp);				/* ����Ʈ ���� ��� ������ ��� */
node_t *searchNode(list_t *lp, int data);	/* data�� ��ġ�ϴ� node �˻� */
bool_t removeNode(list_t *lp, int data);	/* data ��� ���� */
void sortList(list_t *lp);				/* ��� ���� - �������� */
void destoryList(list_t *lp);				/* ����Ʈ ���� ��� ��� ���� */

#endif /* LINKEDLIST_H_ */
