#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Queue.h"
#define MAX 6

int main(void) {
	int r;
	queue_t que;

	srand((unsigned int)time(NULL));
	createQueue(&que, MAX);
	printf("***** �Է°� *****\n");
	for (int i=0 ; i<MAX ; i++) {
		r = (rand() % MAX) + 1;
		printf("%2d ", r);
		if (enqueue(&que, r)) {
			printf("�Է¼���!!!\n");
		}
		else {
			printf("�Է½���!!!\n");
		}
	}

	while (!isQueueEmpty(&que)) {
		dequeue(&que, &r);
		printf("%2d", r);
	}
	printf("\n");
	destroyQueue(&que);
	
	return 0;
}
