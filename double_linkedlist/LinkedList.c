#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#pragma warning(disable : 4996)

/*----------------------------------------------------------------
Function name	: createList() - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------*/
bool_t createList(list_t *lp) {

	if(lp==NULL){
		return FALSE;
	}
	lp->head = (node_t *) malloc(sizeof(node_t));  // head node 할당 
	if(lp->head==NULL){
		return FALSE;
	}
	lp->tail = (node_t *) malloc(sizeof(node_t)); // tail node 할당
	if(lp->tail == NULL){
		free(lp->head); // 이미 head가 동적할당 받음 (메모리누수방지)
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
Function name	: addFirst() - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
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

	// 방향 4개를 재지정해줘야함

	lp->size++;
	
	return TRUE;
}


/*----------------------------------------------------------------
Function name	: 	addLast() - tail node 앞에 새 node 추가(정순 저장)
Parameters		: 	lp - 리스트 관리 구조체의 주소
					data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
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
Function name	: displayList() - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------*/
void displayList(list_t *lp) {

	/* lp포인터 NULL check */
	/* 첫 번째 데이터 노드를 지정한 후 head pointer가 가리키는 주소로 지정  */
	/* 마지막 노드까지의 데이터를 출력한다. lp의 tail pointer 주소를 만나면 멈춤 */

	if (lp == NULL) {
		return;
	}

	node_t *printnode;
	//printnode = (node_t*)malloc(sizeof(node_t)); // 메모리누수 발생
	// printnode에 동적할당주소를 넣었는데 바로아래서 다른주소를 받아서 해제도 불가능

	printnode = lp->head->next;
	while (printnode != lp->tail) {
		printf("%d ", printnode->data);
		printnode = printnode->next;
	}
	printf("\n");
}

/*----------------------------------------------------------------
Function name	: searchNode() - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
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
//Function name	: removeNode() - data와 일치하는 첫 번째 노드 삭제
//Parameters		: lp - 리스트 관리 구조체의 주소
//				  data - 삭제할 데이터
//Returns			: 성공 - TRUE / 실패 - FALSE
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
Function name	: sortList() - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
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
Function name	: destoryList - 리스트 내의 모든 노드
				  (head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
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
	//	printf("뭔가안지워짐\n");
	//}

	return;
}

/*----------------------------------------------------------------
Function name	: searchDupNode() - data와 일치하는 모든  node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
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