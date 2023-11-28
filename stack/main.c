#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"
#define MAX 5
#pragma warning(disable : 4996)
int main(void) {
	stack_t stack;
	int r;
	int i;
	srand((unsigned int)time(NULL));  // 시작위치에서 딱 1회만 호출 / rand 함수 쓰려면 필요함 / time(NULL) 현재시스템내의 시계로부터 현재시간을 읽어옴 srand는 unsigned int를 받으므로 강제 캐스팅

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
