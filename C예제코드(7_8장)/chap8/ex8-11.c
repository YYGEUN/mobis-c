#include<stdio.h>
enum  Nation
{
	KOREA,
	USA,
	JAPAN,
	CHINA
};
int main()
{
	// 나열형 변수를 선언하여 사용할 때의 특징
	enum  Nation x;	//Nation 타입의 x변수 선언을 하면 x변수에는 나열형 선언 시 지정한 상수값 만 저장가능 함

	x = KOREA;  //x = 0; <=== 비 추천 (C언어 수행, C++ 에러발생)
	printf("x=%d\n", x);
	
	// 매크로 상수 대용으로 사용하는 나열형
	printf("%d\n", KOREA);		// 0 출력  #define KOREA (0) 한 효과
	printf("%d\n", USA);		// 1 출력  #define USA	(1)  한 효과
	printf("%d\n", JAPAN);		// 2 출력  #define JAPAN (2) 한 효과
	printf("%d\n", CHINA);		// 3 출력  #define CHINA (3) 한 효과

	getchar();
	return 0;
} // end of main()
