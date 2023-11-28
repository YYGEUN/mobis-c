#ifndef stack_t_H_
#define stack_t_H_

typedef enum _bool { FALSE, TRUE } bool_t;

typedef struct _stack {
	int *stack;		/* 데이터 저장공간 포인터 */
	int size;			/* 스택 크기 */
	int top;			/* 데이터 입출력 참조변수 */
} stack_t;

bool_t createStack(stack_t *sp, int size);	/* 스택 메모리할당 및 멤버 초기화 함수 */
bool_t isStackFull(stack_t *sp);			/* 스택이 꽉 차 있는지 검사 */
bool_t isStackEmpty(stack_t *sp);			/* 스택이 완전히 비어있는지 검사 */
bool_t push(stack_t *sp, int pushData);		/* 스택에 데이터 저장하는 함수 */
bool_t pop(stack_t *sp, int *popData);		/* 스택에서 데이터를 꺼내는 함수 */
/* 스택 내의 모든 데이터 출력 함수 */
void printStack(const stack_t* sp);
void destroyStack(stack_t *sp);				/* 스택 메모리 해제 함수 */


#endif /* STACK_H_ */
