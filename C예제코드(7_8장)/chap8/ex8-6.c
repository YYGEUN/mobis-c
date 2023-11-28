#include<stdio.h>
struct Data1{
	char c;
	short h;
	int i;
	double d;
};
struct Data2{
	char c;
	double d;
	short h;
	int i;
};
struct Data3{
	char c;
	short h;
	double d;
	int i;
};
int main()
{
	struct Data1 v1;
	struct Data2 v2;
	struct Data3 v3;

	printf(" &v1.c : %u\n &v1.h : %u\n &v1.i : %u\n &v1.d : %u\n",
			&v1.c, &v1.h, &v1.i, &v1.d);
	printf("struct Data1 size : %u\n", sizeof(struct Data1));
	printf("--------------------------------------\n\n");

	printf(" &v2.c : %u\n &v2.d : %u\n &v2.h : %u\n &v2.i : %u\n",
			&v2.c, &v2.d, &v2.h, &v2.i);
	printf("struct Data2 size : %u\n", sizeof(struct Data2));

	printf("--------------------------------------\n\n");

	printf(" &v3.c : %u\n &v3.h : %u\n &v3.d : %u\n &v3.i : %u\n",
			&v3.c, &v3.h, &v3.d, &v3.i);
	printf("struct Data3 size : %u\n", sizeof(struct Data3));
	getchar();
	return 0;
}
