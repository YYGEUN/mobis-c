#include<stdio.h>
int plus(int, int);
int minus(int, int);
int multi(int, int);

int main()
{
	int i, res;
	int (*fpAry[4])(int, int) = {plus, minus, multi, plus};

	for(i = 0; i<sizeof(fpAry)/sizeof(fpAry[0]); i++){
		res=fpAry[i](10,20);
		printf("res = %d\n", res);
	}

	getchar();
	return 0;
} // end of main()
int plus(int a, int b)
{
	return a+b;
}
int minus(int a, int b)
{
	return a-b;
}
int multi(int a, int b)
{
	return a*b;
}
