#include<stdio.h>
#include<stdlib.h>/* rand(), srand() */
#include<time.h>/* time() */

int random(int);

int main() {
	int num;
	int i;

	srand((unsigned int)time(NULL)); /* �ʼ� ȣ�� */

	/*
	�ý��� �ð��� ���� ���� ������ ����Ͽ�
	����� ���� �ٸ� ������ �߻��ϵ��� �Ѵ�.
	srand()�Լ��� random()�Լ� ������� �ѹ� �� ȣ���ϵ��� �Ѵ�.
	���� �� ���� �� ���α׷� ����ӵ��� ���ϵȴ�.
	*/
	/* �ݺ����� �̿��ؼ� 5���� ������ �߻����� ��� */
	i = 0;
	while (i < 5) {
		num = random(10); 			/* ���� ���� �Լ��� ȣ�� */
		printf("%d\n", num);
		++i;
	}

	return 0;
}

/* ���� �߻� �Լ� */
int random(int n) {
	int res;
	res = rand() % n;	/* 0���� n-1������ ���� ���� �߻� */

	return res;
}
