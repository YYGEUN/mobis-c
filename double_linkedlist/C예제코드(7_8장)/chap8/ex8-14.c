#include<stdio.h>
#include<malloc.h>
typedef int (*intArrayPtr)[4]; /* int [][4]배열을 가리키는 포인터변수의 형명 재지정 */
intArrayPtr  memoryAllocation(int);
int main()
{
	int row;
	int(*aryPtr)[4] = NULL;

	printf("행(row)의 수 입력 : ");
	scanf("%d", &row);

	aryPtr = memoryAllocation(row);  /* menu에 따른 함수 포인터값 리턴 받기 */
	aryPtr[row-1][3] = 77;
	printf("aryPtr[%d][3] = %d", row-1, aryPtr[row-1][3]);

	free(aryPtr);

	getchar(); getchar();
	return 0;
}
intArrayPtr memoryAllocation(int row)  /* 전달인자의 행수만큼 2차원
배열메모리를 할당하여 주소를 리턴하는 함수*/
/* int (*)[4] memoryAllocation(int row)  는 에러나는 표현 */
/* int (*memoryAllocation(int row))[4] 는 가능한 표현 */
{
	intArrayPtr p;   /*동일표현 : int (*p)[4]=NULL;*/
	p=(intArrayPtr) malloc(row*sizeof(int[4])); /* 동일표현 : p = (int (*)[4])malloc(row*sizeof(int [4])); */

	return p;
}
