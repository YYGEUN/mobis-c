#include<stdio.h>
#include<malloc.h>
int ** myAlloc(int, int);
void dataInput(int **, int, int);
void dataOutput(int **, int, int);
void myDelete(int **, int);
int main()
{
	int  **ip;
	int  col, row;
	printf("row �� �Է� : ");
	scanf("%d", &row);
	printf("column �� �Է� : ");
	scanf("%d", &col);
	ip = myAlloc(row, col);
	if (ip == NULL) {
		return 1;
	}
	dataInput(ip, row, col);
	dataOutput(ip, row, col);
	myDelete(ip, row);
	return 0;
}
// 4���� ����� ���� �Լ� �����ϱ�
