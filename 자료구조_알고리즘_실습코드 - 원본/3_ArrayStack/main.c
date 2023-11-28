#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"
#define MAX 5

int main(void) {
	stack_t stack;
	int r;
	int i;
	srand((unsigned int)time(NULL));  // 시작위치에서 딱 1회만 호출 

	createStack(&stack, MAX);

	printf("***** 입력값  *****\n");
	for (i=0 ; i<MAX+2 ; i++) {
		r = rand() % MAX + 1;
		printf("%d ", r);
		if (push(&stack, r) == TRUE) {
			printf("입력성공!!!\n");
		}
		else {
			printf("입력실패!!!\n");
		}
	}

	printf("출력값 : ");
	while (pop(&stack, &r) == TRUE) {
	
		printf("%d ", r);
	
	}
	printf("\n");

	return 0;
}
