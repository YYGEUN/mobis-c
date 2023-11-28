#include <stdio.h>
#include "QuickSort.h"
#include "BinarySearch.h"

int main(void) {
	int pos,pos2;								/* 원소위치 저장 변수 */
	int n;									/* 찾을 원소 값 */

	int dataList[] = { 76, 12, 54, 3, 15, 6, 34, 29, 25 };
	int size = sizeof(dataList) / sizeof(dataList[0]);

	printf("***** 정렬  전 출력 *****\n");
	output(dataList, size);
	quickSort(dataList, 0, size - 1);		/* 퀵 정렬 함수 호출 */
	printf("***** 정렬  후 출력 *****\n");
	output(dataList, size);
	n = 3;
	pos = binarySearch(dataList, size, n);
	pos2 = binarySearchrecur(dataList, size, n,0,size-1);
	printf("배열내의 %d 값의 위치 : %d\n", n, pos);
	printf("배열내의 %d 값의 위치 : %d\n", n, pos2);

	return 0;
}
