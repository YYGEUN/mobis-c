#include<stdio.h>
#include<malloc.h>
typedef int (*intArrayPtr)[4]; /* int [][4]�迭�� ����Ű�� �����ͺ����� ���� ������ */
intArrayPtr  memoryAllocation(int);
int main()
{
	int row;
	int(*aryPtr)[4] = NULL;

	printf("��(row)�� �� �Է� : ");
	scanf("%d", &row);

	aryPtr = memoryAllocation(row);  /* menu�� ���� �Լ� �����Ͱ� ���� �ޱ� */
	aryPtr[row-1][3] = 77;
	printf("aryPtr[%d][3] = %d", row-1, aryPtr[row-1][3]);

	free(aryPtr);

	getchar(); getchar();
	return 0;
}
intArrayPtr memoryAllocation(int row)  /* ���������� �����ŭ 2����
�迭�޸𸮸� �Ҵ��Ͽ� �ּҸ� �����ϴ� �Լ�*/
/* int (*)[4] memoryAllocation(int row)  �� �������� ǥ�� */
/* int (*memoryAllocation(int row))[4] �� ������ ǥ�� */
{
	intArrayPtr p;   /*����ǥ�� : int (*p)[4]=NULL;*/
	p=(intArrayPtr) malloc(row*sizeof(int[4])); /* ����ǥ�� : p = (int (*)[4])malloc(row*sizeof(int [4])); */

	return p;
}
