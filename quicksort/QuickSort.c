#include <stdio.h>
#include "QuickSort.h"

/*----------------------------------------------------------------
Function name	: output() - 배열의 모든 원소 출력하기
Parameters		: ary - 정렬할 데이터 배열의 시작주소
				  size - 정렬할 데이터의 개수
Returns			: 	없음
----------------------------------------------------------------*/
void output(int arr[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

void output2(person *arr, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%s  %s  %d\n", arr[i].name,arr[i].sex,arr[i].age);
	}
	printf("\n");
}

void output3(double arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf(" %lf ", arr[i]);
	}
	printf("\n");
}

void stringoutput(char (*arr)[10], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf(" %s  ", arr[i]);
	}
	printf("\n");
}

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
	
	output(ary, 9);

	if (right<=left) {
		return;
	}

	pivot = right;
	j = right;
	i = left;

	while (i <= j) {
		while (ary[i] < ary[pivot]) {
			i++;
		}
		while (ary[j] >= ary[pivot]) {
			j--;
			if (i == j) {
				break;
			}
		}
		if (i < j) {
			int tmp = ary[i];
			ary[i] = ary[j];
			ary[j] = tmp;
		}
	}

	temp = ary[pivot];
	ary[pivot] = ary[i];
	ary[i] = temp;

	quickSort(ary, left, i - 1);
	quickSort(ary, i+1, right);

	return;
}
