#include <stdio.h>
#include "QuickSort.h"

/*----------------------------------------------------------------
�Լ��� �� ��� 	: quickSort() - �� ���� �Լ�
��������		: ary - ������ ������ �迭�� �����ּ�
			  left - �迭�� ���� ��
			  right - �迭�� ���� ��
���ϰ�		: ����
----------------------------------------------------------------*/
void quickSort(int ary[], int left, int right) {
	int pivot;
	int temp;
	int i;
	int j;

	// TODO
}

/*----------------------------------------------------------------
Function name	: output() - �迭�� ��� ���� ����ϱ�
Parameters		: ary - ������ ������ �迭�� �����ּ�
	  			  size - ������ �������� ����
Returns			: 	����
----------------------------------------------------------------*/
void output(int arr[], int size) {
	int i;

	for(i=0; i<size; i++) {
		printf(" %d ", arr[i]);
	}
	printf("\n");
}
