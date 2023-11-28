#ifndef QUICKSORT_H_
#define QUICKSORT_H_

typedef struct Person
{
	const char name[20];
	int age;
	const char sex[20];
}person;

/* 퀵 정렬 함수 */
void quickSort(int ary[], int left, int right);

/* 배열 출력 함수 */
void output(int ary[], int size);

#endif /* QUICKSORT_H_ */
