#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _node {
	int data;				/* 데이터 저장 맴버 */
	struct _node *next;		/* 다음 노드 포인터 */
	struct _node *prev;		/* 이전 노드 포인터 */
} node_t;

typedef struct _list {
	node_t *head;			/* head노드 포인터 */
	node_t *tail;			/* tail노드 포인터 */
	int size;				/* 등록 노드 수 카운터 */
} list_t;

bool_t createList(list_t *lp);				/* 연결 리스트 초기화 */
bool_t addFirst(list_t *lp, int data);		/* head node 뒤에 node 추가(역순 저장) */
bool_t addLast(list_t *lp, int data);		/* tail node 앞에 node 추가(정순 저장) */
void displayList(list_t *lp);				/* 리스트 내의 모든 데이터 출력 */
node_t *searchNode(list_t *lp, int data);	/* data와 일치하는 node 검색 */
node_t **searchNodeDuplicate(list_t *lp, int data, int *count); /* data와 일치하는 모든 노드를 검색 */ 
bool_t removeNode(list_t *lp, int data);	/* data 노드 삭제 */
void sortList(list_t *lp);					/* 노드 정렬 - 오름차순 */
void destoryList(list_t *lp);				/* 리스트 내의 모든 노드 삭제 */

#endif /* LINKEDLIST_H_ */
