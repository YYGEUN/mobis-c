#include <stdio.h>
#include "QuickSort.h"

int main(void) {
	int dataList[] = { 76, 12, 54, 3, 15, 6, 34, 29, 25 };
	int size = sizeof(dataList) / sizeof(dataList[0]);

	printf("***** ����  �� ��� *****\n");
	output(dataList, size);
	quickSort(dataList, 0, size - 1);		/* �� ���� �Լ� ȣ�� */
	printf("***** ����  �� ��� *****\n");
	output(dataList, size);
	return 0;
}
