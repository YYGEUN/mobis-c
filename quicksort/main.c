#include <stdio.h>
#include "QuickSort.h"
#include <stdlib.h>
#include <string.h>

//typedef struct Person
//{
//	const char name[20];
//	int age;
//	const char sex[20];
//}person;

void output(int arr[], int size);
void output2(person* arr, int size);
void output3(double arr[], int size);
void stringoutput(char(*arr)[10], int size);

int compare(const int* one, const int* two);
int compare2(const person* one, const person* two);
int compare3(const double* one, const double* two);
int stringcompare(const char* one, const char* two);

int main(void) {
	int dataList[] = { 76, 3, 29, 3, 15, 6, 34, 29, 25 };
	person dataList2[] = {{"aaa",17,"female"},{"bbb",15,"female"},{"ccc",13,"male"}};
	double dataList3[] = { 3.4,3.2,7.7,6.5,5.5 };
	char str[][10] = { "pineapple","apple","ringgo","momo","dragon" };

	int size = sizeof(dataList) / sizeof(dataList[0]);
	int size2 = sizeof(dataList2) / sizeof(dataList2[0]);
	int size3 = sizeof(dataList3) / sizeof(dataList3[0]);
	int size4 = sizeof(str) / sizeof(str[0]);

	printf("***** ����  �� ��� *****\n");
	output(dataList, size);
	output2(dataList2, size2); /* ����ü ������ */
	output3(dataList3, size3);
	stringoutput(str, size4);

	//quickSort(dataList, 0, size - 1);		/* �� ���� �Լ� ȣ�� */

	qsort(dataList, sizeof(dataList) / sizeof(dataList[0]), sizeof(dataList[0]),(int(*)(const void*,const void*))(compare));
	// 1���ڸ��� void* , 2���ڸ��� sort �����Ͱ��� , 3���ڸ��� data 1�� ũ��, 4���ڸ��� compare ��Һ񱳸� ��� �Ұ���
	// *4���ڸ��� ������ int* �����̰� �Ķ���ͷ� const void* �� 2�� �޾ƾ��� ���� ���ô� �Ķ���Ͱ� const void*�̶��ӿ������� 

	qsort(dataList2, sizeof(dataList2) / sizeof(dataList2[0]), sizeof(dataList2[0]), (int(*)(const void*, const void*))(compare2));  /* ����ü ���� */
	qsort(dataList3, sizeof(dataList3) / sizeof(dataList3[0]), sizeof(dataList3[0]), (int(*)(const void*, const void*))(compare3));
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(str[0]), (int(*)(const void*, const void*))(stringcompare));

	printf("***** ����  �� ��� *****\n");
	output(dataList, size);
	output2(dataList2, size2); /* ����ü ���� */
	output3(dataList3, size3);
	stringoutput(str, size4);
	return 0;
}

int compare(const int* one, const int* two) {
	return (*one < *two) ? -1 : 1;
}


int compare2(const person* one, const person* two) {
	if (one->age == two->age) {
		if (strcmp(one->sex,two->sex) < 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	return (one->age < two->age) ? -1 : 1;
}

int compare3(const double* one, const double* two) {
	return (*one < *two) ? -1 : 1;
}

int stringcompare(const char* one, const char* two) {
	if (strcmp(one, two) < 0) {
		return 0;
	}
	else {
		return 1;
	}
}
