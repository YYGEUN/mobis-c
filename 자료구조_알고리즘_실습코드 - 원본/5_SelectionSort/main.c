#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "SelectionSort.h"

int main() {
	int numberArray[10];
	int arySize;
	arySize = sizeof(numberArray)/sizeof(numberArray[0]);
	srand((unsigned int)time(NULL));

	initArray(numberArray, arySize);
	printArray(numberArray, arySize);
	selectionSort(numberArray, arySize);
	printArray(numberArray, arySize);

	return 0;
}
