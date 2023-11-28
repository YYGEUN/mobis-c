#include<stdio.h>
int main()
{
	int ary[]={1,2,3,4,5};

	printf( "%p\n", ary );
	printf( "%p\n", (ary+3) );			// 주소상수와 정수와의 덧셈 연산
	printf( "%u\n", *(ary+3) );
	printf( "%u\n", &ary[5] - &ary[2] );	// 주소상수끼리의 뺄셈 연산

	getchar();
	return 0;
}
