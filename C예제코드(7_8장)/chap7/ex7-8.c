#include<stdio.h>
#include<stdlib.h>
int * myAlloc(int);
void dataInput(int *, int);
void dataOutput(int *, int);
void myDelete(int *);
int main()
{
	int  *ip = NULL;
	int  col;
	printf("column �� �Է� : ");
	scanf("%d", &col);
	ip = myAlloc(col);
	if (ip == NULL) {
		return 1;
	}
	dataInput(ip, col);
	dataOutput(ip, col);
	myDelete(ip);
	return 0;
}
// 4���� ����� ���� �Լ� �����ϱ�
