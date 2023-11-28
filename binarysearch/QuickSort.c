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

	if (left >= right)
		return;

	i = left - 1;
	j = right;
	pivot = ary[right];

	do {
		while (ary[++i] < pivot);
		while ((--j >= 0) && (ary[j] > pivot));

		if (i < j) {
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
	} while (i < j);

	temp = ary[i];
	ary[i] = ary[right];
	ary[right] = temp;

	quickSort(ary, left, i - 1);
	quickSort(ary, i + 1, right);
}

/*----------------------------------------------------------------
Function name	: output() - �迭�� ��� ���� ����ϱ�
Parameters		: ary - ������ ������ �迭�� �����ּ�
	  			  size - ������ �������� ����
Returns			: 	����
----------------------------------------------------------------*/
void output(int arr[], int size) {
	int i;

	for(i = 0 ; i < size ; ++i) {
		printf(" %d ", arr[i]);
	}
	printf("\n");
}
