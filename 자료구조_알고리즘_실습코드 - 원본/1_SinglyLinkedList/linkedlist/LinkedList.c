#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*----------------------------------------------------------------
Function name	: createList() - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------*/
bool_t createList(list_t *lp) {

	if(lp==NULL){
		return FALSE;
	}
	lp->head = (node_t *) malloc(sizeof(node_t));  // head node �Ҵ� 
	if(lp->head==NULL){
		return FALSE;
	}
	lp->tail = (node_t *) malloc(sizeof(node_t)); // tail node �Ҵ�
	if(lp->tail == NULL){
		free(lp->head);
		return FALSE;
	}
	lp->head->next = lp->tail;
	lp->tail->next = lp->tail;
	lp->head->prev = lp->head;
	lp->tail->prev = lp->head;
	lp->size = 0;

	return TRUE;
}

/*--------------------------------------------------------------
Function name	: addFirst() - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
--------------------------------------------------------------*/
bool_t addFirst(list_t *lp, int data) {
	node_t *newp;
	if(lp==NULL){
		return FALSE;
	}
	newp = (node_t *) malloc(sizeof(node_t)); 
	if(newp==NULL){
		return FALSE;
	}
	newp->data = data;
	newp->next = lp->head->next;
	lp->head->next = newp;
	newp->prev = lp->head;
	newp->next->prev = newp;
	
	lp->size++;
	
	return TRUE;
}


/*----------------------------------------------------------------
Function name	: 	addLast() - tail node �տ� �� node �߰�(���� ����)
Parameters		: 	lp - ����Ʈ ���� ����ü�� �ּ�
					data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------*/
bool_t addLast(list_t *lp, int data) {

	node_t *newp;
	if(lp==NULL){
		return FALSE;
	}
	newp = (node_t *) malloc(sizeof(node_t));
	if(newp == NULL){
		return FALSE;
	}

	newp->data = data;
	newp->prev = lp->tail->prev;
	newp->next = lp->tail;
	newp->prev->next = newp;
	newp->next->prev = newp;
	lp->size++;
	return TRUE;
}

/*----------------------------------------------------------------
Function name	: displayList() - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------*/
void displayList(list_t *lp) {

	/* lp������ NULL check */
	/* ù ��° ������ ��带 ������ �� */
	/* ������ �������� �����͸� ����Ѵ�. */
	node_t *tp;
	if(lp==NULL){
		return;
	}
	tp = lp->head->next;
	while(tp != lp->tail){
		printf("%5d", tp->data);
		tp=tp->next;
	}
	printf("\n");
}

/*----------------------------------------------------------------
Function name	: searchNode() - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------*/
node_t *searchNode(list_t *lp, int data) {
	node_t *tp;
	if(lp==NULL){
		return NULL;
	}
	
	tp=lp->head->next;
	
	while(tp!=lp->tail){
		if(tp->data == data){
			return tp;
		}
		tp= tp->next;
	}
	return NULL;
}
/*----------------------------------------------------------------
Function name	: searchDupNode() - data�� ��ġ�ϴ� ���  node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ? 
----------------------------------------------------------------*/
(      ) searchDupNode(list_t *lp, int data) {
	node_t *tp;
	if(lp==NULL){
		return NULL;
	}
	
	tp=lp->head->next;
	
	while(tp!=lp->tail){
		if(tp->data == data){
			return tp;
		}
		tp= tp->next;
	}
	return NULL;
}

/*----------------------------------------------------------------
Function name	: removeNode() - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------*/
bool_t removeNode(list_t *lp, int data) {
	node_t *dp;
	if(lp==NULL){
		return FALSE;
	}
	
	dp = searchNode(lp, data);
	if(dp != NULL){
		dp->prev->next = dp->next;
		dp->next->prev = dp->prev;
		free(dp);
		lp->size--;
		return TRUE;
	}
	else{
		return FALSE;
	}
}

/*----------------------------------------------------------------
Function name	: sortList() - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------*/
void sortList(list_t *lp) {

	node_t *np;
	node_t *tp;
	int tmp;

	if (lp == NULL) {
		return;
	}

	np = lp->head->next;

	while (np->next != lp->tail) {
		while (tp != lp->tail) {
			if (np->data > tp->data) {
				tmp = np->data;
				np->data = tp->data;
				tp->data = tmp;
			}
			tp = tp->next;
		}
		np = np->next;
	}

}

/*----------------------------------------------------------------
Function name	: destoryList - ����Ʈ ���� ��� ���
				  (head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------*/
void destoryList(list_t *lp) {
	node_t *np, *tp;
	if(lp==NULL){
		return;
	}

	tp=lp->head->next;
	while(tp!=lp->tail){
		np = tp->next;
		//printf("[%d] ", tp->data);
		free(tp);
		tp = np;
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
}

