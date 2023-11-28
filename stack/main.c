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
	srand((unsigned int)time(NULL));  // ������ġ���� �� 1ȸ�� ȣ�� / rand �Լ� ������ �ʿ��� / time(NULL) ����ý��۳��� �ð�κ��� ����ð��� �о�� srand�� unsigned int�� �����Ƿ� ���� ĳ����

	createStack(&stack, MAX);

	printf("***** �Է°�  *****\n");
	for (i=0 ; i<MAX+2 ; i++) {
		r = rand() % MAX + 1;
		printf("%d ", r);
		if (push(&stack, r) == TRUE) {
			printf("�Է¼���!!!\n");
		}
		else {
			printf("�Է½���!!!\n");
		}
	}

	printf("��°� : ");
	while (pop(&stack, &r) == TRUE) {
	
		printf("%d ", r);
	
	}
	printf("\n");

	return 0;
}
