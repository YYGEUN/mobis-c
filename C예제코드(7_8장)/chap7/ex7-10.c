#include  <stdio.h>
int  plus(int, int) ;
int main()
{
	int  a =10, b = 20 ;
	int  res ;
	int  (*fptr) (int,int);	// plus()�Լ��� ����Ű�� �����ͺ��� ����
	fptr  = plus ;		// �Լ������ͷ� �Լ� ����Ű��
	res =  fptr(a, b) ;	// �Լ�ȣ��� : res = (* fptr)(a, b) ;
	printf("%d + %d = %d\n", a, b, res) ;

	getchar();
	return 0;
}
int   plus(int  x,  int  y)
{
	return (x + y) ;
}
