#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
	int data;				/* ������ ���� �ɹ� */
	struct _node *next;		/* ���� ��� ������ */
	struct _node *prev;		/* ���� ��� ������ */
} node_t;

typedef struct _list {
	node_t *head;			/* head��� ������ */
	node_t *tail;			/* tail��� ������ */
	int size;				/* ��� ��� �� ī���� */
} list_t;

bool_t createList(list_t *lp);				/* ���� ����Ʈ �ʱ�ȭ */
bool_t addFirst(list_t *lp, int data);		/* head node �ڿ� node �߰�(���� ����) */
bool_t addLast(list_t *lp, int data);		/* tail node �տ� node �߰�(���� ����) */
void displayList(list_t *lp);				/* ����Ʈ ���� ��� ������ ��� */
node_t *searchNode(list_t *lp, int data);	/* data�� ��ġ�ϴ� node �˻� */
node_t **searchNodeDuplicate(list_t *lp, int data, int *count); /* data�� ��ġ�ϴ� ��� ��带 �˻� */ 
bool_t removeNode(list_t *lp, int data);	/* data ��� ���� */
void sortList(list_t *lp);					/* ��� ���� - �������� */
void destoryList(list_t *lp);				/* ����Ʈ ���� ��� ��� ���� */

#endif /* LINKEDLIST_H_ */
