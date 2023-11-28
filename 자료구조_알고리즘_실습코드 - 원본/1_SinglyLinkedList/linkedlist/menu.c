#include <stdio.h>
#include "menu.h"

/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
static void myFlush(void) {
	while (getchar() != '\n') {
		;
	}
}

/*----------------------------------------------------------------------------------
Function name	: menu
Parameters		: mList - �޴� ��� �迭
				  menuCnt - �޴� ����
Returns			: ����� ������ �޴���ȣ
----------------------------------------------------------------------------------*/
int menu(const char **menuStr, int menuCnt) {
	int i;
	int num;
	int res;

	num = 0;
	do {
		for (i=0 ; i<menuCnt ; i++) {
			printf("%d. %s\n", i+1, menuStr[i]);
		}
		printf("�޴���ȣ�Է� : ");
		res = scanf("%d", &num);
		myFlush();
		if (res != 1) {
			printf("�߸� �Է��Ͽ����ϴ�.\n");
		}
	} while ((num < 1) || (num > menuCnt));

	return num;
}

/*----------------------------------------------------------------------------------
Function name	: mInput - �Է� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mInput(list_t *lp) {
	int inData;
	int res;  /* scanf()�Լ��� ���� �� ���� */
	bool_t bres;

	printf("\n[ �Է��ϱ� �޴� ]\n\n");

	while (1) {
		printf("# ������ �Է��ϼ���(���� �Է½� ����) : ");
		res = scanf("%d", &inData);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/

		if (res == 0) {	/* ���� �Է� �� ���� */
			myFlush();
			break;
		}

		bres = addLast(lp, inData);	/* tail ��� �տ� ������ �߰�  */
		if (bres == TRUE)
			printf("@ ������ �߰� ����!\n");
		else
			printf("@ ������ �߰� ����!\n");
	}
	return;
}

/*----------------------------------------------------------------------------------
Function name	: mOutput - ��� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mOutput(list_t *lp) {
	displayList(lp);
}

/*----------------------------------------------------------------------------------
Function name	: mSearch - �˻� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSearch(list_t * lp) {
	int sData;
	node_t *resp;		/* �˻��� ����� �����ּ� ���� */
	int res;			/* scanf()�Լ��� ���� �� ���� */

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while (1) {
		printf("# ã�� �����͸� �Է��ϼ���(���� �Է� �� ����) : ");
		res = scanf("%d", &sData);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/

		if (res == 0) {				/* ���� �Է� �� ���� */
			myFlush();
			break;
		}
		else {
			;
		}

		resp = searchNode(lp, sData);
		if (resp != NULL) {	/* �����͸� ã������ */
			printf("@ �˻� ������ ����!\n");
		}
		else {				/* �����͸� ��ã������ */
			printf("@ �˻� ������ �������� ����!\n");
		}
	}
	return;
}

/*----------------------------------------------------------------------------------
Function name	: mDelete - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mDelete(list_t * lp) {
	int delData;
	int res;							/* scanf()�Լ��� ���� �� ���� */
	bool_t bres;

	printf("\n[ �����ϱ� �޴� ]\n\n");
	while (1) {
		printf("# ������ �����͸� �Է��ϼ���(���� �Է� �� ����) : ");
		res = scanf("%d", &delData);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/

		if (res == 0) {					/* ���� �Է� �� ���� */
			myFlush();
			break;
		}
		else {
			;
		}

		bres = removeNode(lp, delData);
		if (bres == TRUE) {
			printf("@ ���� ����!\n");
		}
		else {
			printf("@ ���� ����!\n");
		}
	}
	return;
}

