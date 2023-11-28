#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Queue.h"
#define MAX 12
#pragma warning(disable : 4996)

int main(void) {
	queue_t que;
	int n;
	int tmp;

	createQueue(&que, MAX);
	
	printf("***** ÀÔ·Â°ª *****\n");
	scanf("%d", &n);

	for (int i = 1; i < MAX; i++) {
		enqueue(&que, i);
	}

	printQueue(&que);

	int now = 1;
	while (!isQueueEmpty(&que))
	{
		if ((now)%n != 0) {
			dequeue(&que, &tmp);
			enqueue(&que, tmp);
		}
		else {
			dequeue(&que, &tmp);
			printf("%d  ", tmp);
		}
		now = (now + 1) % MAX;
	}

	destroyQueue(&que);
	


	return 0;
}
