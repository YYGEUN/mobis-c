#ifndef QUICKSORT_H_
#define QUICKSORT_H_

typedef struct Person
{
	const char name[20];
	int age;
	const char sex[20];
}person;

/* �� ���� �Լ� */
void quickSort(int ary[], int left, int right);

/* �迭 ��� �Լ� */
void output(int ary[], int size);

#endif /* QUICKSORT_H_ */
