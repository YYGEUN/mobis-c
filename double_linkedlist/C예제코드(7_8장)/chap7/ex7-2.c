#include<stdio.h>
int main()
{
	int ary[]={1,2,3,4,5};

	printf( "%p\n", ary );
	printf( "%p\n", (ary+3) );			// �ּһ���� �������� ���� ����
	printf( "%u\n", *(ary+3) );
	printf( "%u\n", &ary[5] - &ary[2] );	// �ּһ�������� ���� ����

	getchar();
	return 0;
}
