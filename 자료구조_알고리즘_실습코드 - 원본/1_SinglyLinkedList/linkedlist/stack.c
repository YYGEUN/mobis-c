#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*--------------------------------------------------------------
Function name	: createStack() - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���� ���� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
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
Function name	: isStackFull() - ������ �� �� �ִ��� �˻�
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ������ �� �� ������ TRUE, �ƴϸ� FALSE ����
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
Function name	: isStackEmpty() - ������ ������ ��� �ִ��� �˻�
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ������ ������ ��� ������ TRUE, �ƴϸ� FALSE ����
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
Function name	: push() - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���� ���� ����ü�� �ּ�
				  pushData - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
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
Function name	: pop() - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���� ���� ����ü�� �ּ�
				  popData -  ���� �����͸� ������ ��� ������ �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
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
Function name	: printStack() - ������ ��� ������ ���
								(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------*/
void printStack(const stack_t* sp) {

	int i;
	for (i=sp->top ; i>0 ; i--) {
		printf("%d ", sp->stack[i - 1]);
	}
	printf("\n");
}

/* --------------------------------------------------------------------------------------------------------------
Function name	: destroyStack() -  ���� �Ҹ� �Լ�
Parameters		: sp - ���� ���� ����ü�� �ּ�
Returns			: ����
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




