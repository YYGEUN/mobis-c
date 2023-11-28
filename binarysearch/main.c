#include <stdio.h>
#include "QuickSort.h"
#include "BinarySearch.h"

int main(void) {
	int pos,pos2;								/* ������ġ ���� ���� */
	int n;									/* ã�� ���� �� */

	int dataList[] = { 76, 12, 54, 3, 15, 6, 34, 29, 25 };
	int size = sizeof(dataList) / sizeof(dataList[0]);

	printf("***** ����  �� ��� *****\n");
	output(dataList, size);
	quickSort(dataList, 0, size - 1);		/* �� ���� �Լ� ȣ�� */
	printf("***** ����  �� ��� *****\n");
	output(dataList, size);
	n = 3;
	pos = binarySearch(dataList, size, n);
	pos2 = binarySearchrecur(dataList, size, n,0,size-1);
	printf("�迭���� %d ���� ��ġ : %d\n", n, pos);
	printf("�迭���� %d ���� ��ġ : %d\n", n, pos2);

	return 0;
}
