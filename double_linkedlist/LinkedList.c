#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#pragma warning(disable : 4996)

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
		free(lp->head); // �̹� head�� �����Ҵ� ���� (�޸𸮴�������)
		return FALSE;
	}
	lp->head->next = lp->tail;
	lp->head->prev = lp->head;
	lp->head->data = 0;
	lp->tail->next = lp->tail;
	lp->tail->prev = lp->head;
	lp->tail->data = 0;
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
	node_t *addhead;
	if(lp==NULL){
		return FALSE;
	}
	addhead = (node_t *) malloc(sizeof(node_t));
	if(addhead == NULL){
		return FALSE;
	}

	addhead->data = data;

	addhead->prev = lp->head;
	addhead->next = lp->head->next;
	lp->head->next = addhead;
	addhead->next->prev = addhead;

	// ���� 4���� �������������

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
	node_t* addlast;
	if (lp == NULL) {
		return FALSE;
	}
	addlast = (node_t*)malloc(sizeof(node_t));
	if (addlast == NULL) {
		return FALSE;
	}

	addlast->data = data;

	addlast->prev = lp->tail->prev;
	addlast->next = lp->tail;
	lp->tail->prev = addlast;
	addlast->prev->next = addlast;
	
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
	/* ù ��° ������ ��带 ������ �� head pointer�� ����Ű�� �ּҷ� ����  */
	/* ������ �������� �����͸� ����Ѵ�. lp�� tail pointer �ּҸ� ������ ���� */

	if (lp == NULL) {
		return;
	}

	node_t *printnode;
	//printnode = (node_t*)malloc(sizeof(node_t)); // �޸𸮴��� �߻�
	// printnode�� �����Ҵ��ּҸ� �־��µ� �ٷξƷ��� �ٸ��ּҸ� �޾Ƽ� ������ �Ұ���

	printnode = lp->head->next;
	while (printnode != lp->tail) {
		printf("%d ", printnode->data);
		printnode = printnode->next;
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
	if (lp == NULL) {
		return NULL;
	}

	node_t* sn;
	sn = lp->head->next;
	while (sn != lp->tail)
	{
		if (sn->data == data)
		{
			return sn;
		}
		sn = sn->next;
	}

	return NULL;
}

/*----------------------------------------------------------------
//Function name	: removeNode() - data�� ��ġ�ϴ� ù ��° ��� ����
//Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
//				  data - ������ ������
//Returns			: ���� - TRUE / ���� - FALSE
//----------------------------------------------------------------*/
bool_t removeNode(list_t *lp, int data) {
	node_t *rn;
	//node_t* tn;

	if (lp == NULL) {
		return FALSE;
	}

	rn = searchNode(lp, data);

	if (rn != NULL)
	{
		rn->next->prev = rn->prev;
		rn->prev->next = rn->next;
		free(rn);
		lp->size -= 1;
		return TRUE;
	}

	return FALSE;
	
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
		tp = np->next;
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
		free(tp);
		tp = np;
	}

	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
	//node_t* dn;
	//node_t* prev_dn;

	//if (lp == NULL) {
	//	return;
	//}

	//dn = lp->head->next;
	//prev_dn = lp->head;

	//while (dn != lp->tail)
	//{
	//	prev_dn = dn;
	//	dn = dn->next;
	//	lp->head->next = dn;
	//	lp->size -= 1;
	//	free(prev_dn);
	//}

	//free(lp->head);
	//free(lp->tail);
	//lp->head = NULL;
	//lp->tail = NULL;

	//if (lp->size != 0) {
	//	printf("������������\n");
	//}

	return;
}

/*----------------------------------------------------------------
Function name	: searchDupNode() - data�� ��ġ�ϴ� ���  node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ?
----------------------------------------------------------------*/
node_t** searchDupNode(list_t* lp, int data, int* cnt) {
	node_t* tp;
	node_t** sdn;

	if (lp == NULL) {
		return NULL;
	}

	tp = lp->head->next;

	while (tp != lp->tail) {
		if (tp->data == data) {
			(*cnt) += 1;
		}
		tp = tp->next;
	}

	sdn = (node_t**) malloc((*cnt) * sizeof(node_t*));
	if (sdn == NULL) return NULL;
	tp = lp->head->next;
	int now = 0;

	printf("a\n");

	if ((*cnt) != 0)
	{	
		while (tp != lp->tail) {
			if (tp->data == data) {
				printf("b\n");
				sdn[now++] = tp;
			}
			tp = tp->next;
		}
		return sdn;
	}

	return NULL;
}