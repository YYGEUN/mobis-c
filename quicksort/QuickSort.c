#include <stdio.h>
#include "QuickSort.h"

/*----------------------------------------------------------------
Function name	: output() - �迭�� ��� ���� ����ϱ�
Parameters		: ary - ������ ������ �迭�� �����ּ�
				  size - ������ �������� ����
Returns			: 	����
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
