#include  <stdio.h>
int  plus(int, int) ;
int main()
{
	int  a =10, b = 20 ;
	int  res ;
	int  (*fptr) (int,int);	// plus()함수를 가리키는 포인터변수 선언
	fptr  = plus ;		// 함수포인터로 함수 가리키기
	res =  fptr(a, b) ;	// 함수호출부 : res = (* fptr)(a, b) ;
	printf("%d + %d = %d\n", a, b, res) ;

	getchar();
	return 0;
}
int   plus(int  x,  int  y)
{
	return (x + y) ;
}
