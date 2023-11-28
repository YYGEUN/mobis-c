#include <stdio.h>
#include <time.h>		/* time() */
#include <stdlib.h>		/* rand(), srand() */
#include "BubbleSort.h"

int main(void) {
	int numberArray[10];
	int arySize;
	arySize = sizeof(numberArray)/sizeof(numberArray[0]);
	srand((unsigned int) time(NULL));

	initArray(numberArray, arySize);
	bubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);

	return 0;
}
