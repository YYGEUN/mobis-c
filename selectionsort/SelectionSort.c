#include <stdio.h>
#include <stdlib.h>
#include "SelectionSort.h"

void initArray(int *ary, int n) {
	int i;
	for(i=0; i<n; ++i) {
		ary[i] = rand() % 20 + 1;
	}
}

void printArray(int *ary, int n) {
	int i;
	printf("배열 내용 : ");
	for(i=0; i<n; ++i) {
		printf("%4d", ary[i]);
	}
	printf("\n");
}

/*----------------------------------------------------------------
Function Name 	: selectionSort() - 선택정렬 함수
Argument 		: ary - 정렬 데이터 저장 배열
 	 	 	 	  n - 배열 원소의 수
Return			: 없음
-----------------------------------------------------------------*/
void selectionSort(int *ary, int n) {

	for (size_t i = 0; i < n-1; i++)
	{
		int midx = i;
		for (size_t j = i + 1; j < n; j++) {
			if (ary[midx] > ary[j]) {
				midx = j;
			}
		}
		int tmp = ary[i];
		ary[i] = ary[midx];
		ary[midx] = tmp;
	}
}
