#include<stdio.h>
#include<stdlib.h>/* rand(), srand() */
#include<time.h>/* time() */

int random(int);

int main() {
	int num;
	int i;

	srand((unsigned int)time(NULL)); /* 필수 호출 */

	/*
	시스템 시간을 난수 씨앗 값으로 사용하여
	실행시 마다 다른 난수가 발생하도록 한다.
	srand()함수는 random()함수 사용전에 한번 만 호출하도록 한다.
	여러 번 수행 시 프로그램 실행속도가 저하된다.
	*/
	/* 반복문을 이용해서 5개의 난수를 발생시켜 출력 */
	i = 0;
	while (i < 5) {
		num = random(10); 			/* 난수 생성 함수의 호출 */
		printf("%d\n", num);
		++i;
	}

	return 0;
}

/* 난수 발생 함수 */
int random(int n) {
	int res;
	res = rand() % n;	/* 0부터 n-1까지의 수중 난수 발생 */

	return res;
}
