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
	printf("row 수 입력 : ");
	scanf("%d", &row);
	printf("column 수 입력 : ");
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
// 4개의 사용자 정의 함수 구현하기
