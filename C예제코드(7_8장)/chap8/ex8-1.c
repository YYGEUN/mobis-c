#include<stdio.h>
struct Person
{
	const char *name;
	char addr[40];
	int  age;
};
struct  Student
{
	int number;
	struct Person  info;
};
int main()
{
char *c[3]={"Gromit", "Gogumi", "Goguma"};

char **p=c;

printf("%c\n", *(*p+2));


	getchar();
	return 0;
}
