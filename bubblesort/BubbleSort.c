#include <stdio.h>
#include <time.h>		/* time() */
#include <stdlib.h>		/* rand(), srand() */
#include "BubbleSort.h"

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
Function Name	: bubbleSort() - ��ǰ���� �Լ�
Argument		: ary - ���� ������ ���� �迭
 	 	 	 	  n - �迭 ������ ��
Return			: ����
----------------------------------------------------------------*/
void bubbleSort(int *ary, int n) {
   
	
	for (size_t i = 0; i < n; i++)
	{
		int flag = 0;
		for (size_t j = 0; j < n-i-1; j++) {
			if (ary[j+1] < ary[j])
			{
				int tmp = ary[j+1];
				ary[j+1] = ary[j];
				ary[j] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}

		printArray(ary, n);
	}
}
