#include <stdio.h>
#include "QuickSort.h"

/*----------------------------------------------------------------
함수명 및 기능 	: quickSort() - 퀵 정렬 함수
전달인자		: ary - 정렬할 데이터 배열의 시작주소
			  left - 배열의 하한 값
			  right - 배열의 상한 값
리턴값		: 없음
----------------------------------------------------------------*/
void quickSort(int ary[], int left, int right) {
	int pivot;
	int temp;
	int i;
	int j;

	// TODO
}

/*----------------------------------------------------------------
Function name	: output() - 배열의 모든 원소 출력하기
Parameters		: ary - 정렬할 데이터 배열의 시작주소
	  			  size - 정렬할 데이터의 개수
Returns			: 	없음
----------------------------------------------------------------*/
void output(int arr[], int size) {
	int i;

	for(i=0; i<size; i++) {
		printf(" %d ", arr[i]);
	}
	printf("\n");
}
