#include<stdio.h>
enum  Nation
{
	KOREA,
	USA,
	JAPAN,
	CHINA
};
int main()
{
	// ������ ������ �����Ͽ� ����� ���� Ư¡
	enum  Nation x;	//Nation Ÿ���� x���� ������ �ϸ� x�������� ������ ���� �� ������ ����� �� ���尡�� ��

	x = KOREA;  //x = 0; <=== �� ��õ (C��� ����, C++ �����߻�)
	printf("x=%d\n", x);
	
	// ��ũ�� ��� ������� ����ϴ� ������
	printf("%d\n", KOREA);		// 0 ���  #define KOREA (0) �� ȿ��
	printf("%d\n", USA);		// 1 ���  #define USA	(1)  �� ȿ��
	printf("%d\n", JAPAN);		// 2 ���  #define JAPAN (2) �� ȿ��
	printf("%d\n", CHINA);		// 3 ���  #define CHINA (3) �� ȿ��

	getchar();
	return 0;
} // end of main()
