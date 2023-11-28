#include<stdio.h>
void sub1(void);
void sub2(void);
void sub3(void);
int main()
{
	typedef void (*func_t)(void);  /* 함수 포인터 변수의 타입 재정의 */
	/* typedef void (*)(void)  func_t; error 발생하는 타입 재정의 표현 */
	/* typedef 키워드로 재정의한 자료형은 관례적으로 _t접미사를 갖는다 */
	int i;
	func_t  *fptr;  /* 함수 포인터 변수를 가리키는 포인터 선언 */
	func_t  funAry[3] = {sub1, sub2, sub3};
	fptr=funAry;
	for(i=0; i<3; i++) {
		fptr[i]();
		funAry[i]();
		printf("\n");
	}

	getchar();
	return 0;
}

void sub1(void)
{
	printf("나는 sub1()함수~\n");
}
void sub2(void)
{
	printf("나는 sub2()함수~\n");
}
void sub3(void)
{
	printf("나는 sub3()함수~\n");
}

