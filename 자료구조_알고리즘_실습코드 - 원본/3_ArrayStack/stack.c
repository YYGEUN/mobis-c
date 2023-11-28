#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*--------------------------------------------------------------
Function name	: createStack() - 지정된 크기의 스택을 생성하는 함수
Parameters		: sp - 스택 관리 구조체의 주소
				  size - 스택의 크기
Returns			: 성공 - TRUE / 실패 - FALSE
--------------------------------------------------------------*/
bool_t createStack(stack_t *sp, int size) {
	if(sp==NULL){
		return FALSE;
	}
	sp->stack = (int *) malloc(sizeof(int) * size);
	if(sp->stack==NULL){
		return FALSE;
	}
	sp->size = size;
	sp->top = 0;

	return TRUE;
}

/*--------------------------------------------------------------
Function name	: isStackFull() - 스택이 꽉 차 있는지 검사
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 스택이 꽉 차 있으면 TRUE, 아니면 FALSE 리턴
--------------------------------------------------------------*/
bool_t isStackFull(stack_t *sp) {

	if(sp==NULL){
		return TRUE;
	}
	if(sp->top==sp->size){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

/* -------------------------------------------------------------
Function name	: isStackEmpty() - 스택이 완전히 비어 있는지 검사
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 스택이 완전히 비어 있으면 TRUE, 아니면 FALSE 리턴
--------------------------------------------------------------*/
bool_t isStackEmpty(stack_t *sp) {

	if(sp==NULL){
		return TRUE;
	}
	if(sp->top==0){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

/* -------------------------------------------------------------
Function name	: push() - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택 관리 구조체의 주소
				  pushData - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------*/
bool_t push(stack_t *sp, int pushData) {

	if(sp==NULL){
		return FALSE;
	}
	if(isStackFull(sp)==TRUE){
		return FALSE;
	}
	
	sp->stack[sp->top++] = pushData;
	
	return TRUE;
}

/* -------------------------------------------------------------
Function name	: pop() - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택 관리 구조체의 주소
				  popData -  꺼낸 데이터를 저장할 기억 공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------*/
bool_t pop(stack_t *sp, int *popData) {

	if(sp==NULL){
		return FALSE;
	}
	if(isStackEmpty(sp)==TRUE){
		return FALSE;
	}
	*popData = sp->stack[--sp->top];
	return TRUE;
}

/* -------------------------------------------------------------
Function name	: printStack() - 스택의 모든 데이터 출력
								(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------*/
void printStack(const stack_t* sp) {

	int i;
	for (i=sp->top ; i>0 ; i--) {
		printf("%d ", sp->stack[i - 1]);
	}
	printf("\n");
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: destroyStack() -  스택 소멸 함수
Parameters		: sp - 스택 관리 구조체의 주소
Returns			: 없음
---------------------------------------------------------------------------------------------------------------*/
void destroyStack(stack_t *sp) {

	if(sp==NULL){
		return;
	}
	if(sp->stack!=NULL){
		free(sp->stack);
	}
	sp->stack = NULL;
	sp->size = 0;
	sp->top = 0;
	return;
}




