#include <stdio.h>
#include "menu.h"
#include "LinkedList.h"
#pragma warning(disable : 4996)
int main(void) {
	const char *menuList[] = { "�Է��ϱ�", "����ϱ�", "�˻��ϱ�", "�����ϱ�", "��ü����" ,"�����ϱ�", "�ߺ��˻�" ,"��  ��"};

	int menuNum;								/* �޴���ȣ ���� ���� */
	int menuCnt;								/* �޴����� ���� ���� */
	list_t list;								/* ����Ʈ���� ����ü ���� */
	bool_t bres;
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	bres = createList(&list);					/* ��� �ִ� ����Ʈ �ʱ�ȭ */
	if (bres == TRUE) {
		printf("@ list ���� ����!\n");
	}
	else {
		printf("@ list ���� ����!\n");
	}

	while (1) {
		menuNum = menu(menuList, menuCnt); 	/* �޴���� �� �޴���ȣ �Է� */

		if (menuNum == menuCnt) { break; }
		switch (menuNum){
		case 1: 			/* �Է¸޴� ���� */
			mInput(&list);
			break;
		case 2: 			/* ��¸޴� ���� */
			mOutput(&list);
			break;
		case 3: 			/* �˻��޴� ���� */
			mSearch(&list);
			break;
		case 4: 			/* �����޴� ���� */
			mDelete(&list);
			break;
		case 5: 			/* ��ü�����޴� ���� */
			mDestroy(&list);
			break;
		case 6: 			/* ���ĸ޴� ���� */
			mSort(&list);
			break;		
		case 7: 			/* �ߺ��˻��޴� ���� */
			mSearchduplicate(&list);
			break;

		default:
			;
			break;
		}
	}
	printf("list���� ������ ����� ���� : %d\n", list.size);
	destoryList(&list);						/* ����Ʈ���� ��� ������ ���� */

	return 0;
}

