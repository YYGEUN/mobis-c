#include <stdio.h>
#include <string.h>
int  main()
{
	const char *p = "C program";
	char str[20] = "C program";

	// 문자열 변경 가능 여부를 판단해보세요.
	p[0] = 'B';
	str[0] = 'B';

	printf("p : %s\n", p);
	printf("str : %s\n", str);
	strcpy(p, "Java");
	strcpy(str, "Java");

	printf("p : %s\n", p);
	printf("str : %s\n", str);

	p = "Python";
	str = "Python";

	printf("p : %s\n", p);
	printf("str : %s\n", str);

	return 0;
}
