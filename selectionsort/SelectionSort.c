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
	printf("�迭 ���� : ");
	for(i=0; i<n; ++i) {
		printf("%4d", ary[i]);
	}
	printf("\n");
}

/*----------------------------------------------------------------
Function Name 	: selectionSort() - �������� �Լ�
Argument 		: ary - ���� ������ ���� �迭
 	 	 	 	  n - �迭 ������ ��
Return			: ����
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
