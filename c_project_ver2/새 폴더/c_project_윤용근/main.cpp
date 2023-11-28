#include <stdio.h>
#include <stdlib.h>
#include "Appliance.h"
#include "HomeAutomation.h"

#pragma warning(disable : 4996)

#define MENU_CNT 7

HomeAuto_t HomeAuto;
APP_t app;
list_app_t machineList[TYPENUMBER];

int main() {
	const char* menuList[] = {"Ȩ���� ����","��� ��ǰ����", "��ǰ ������" ,"������ǰ �߰�", "������ǰ ����" ,"������ǰ ����", "���� ���� ���"};
	int menuNum;								/* �޴���ȣ ���� ���� */
	int menuCnt;								/* �޴����� ���� ���� */
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	//const char* electromachine[TYPENUMBER] = { "AirConditioner","Light","CooCoo","Washingmachine" };

	HomeAuto.appCnt = 0; // Ȥ�ø��� �ʱⰪ ����


	if (createListappliance(&HomeAuto) == 0) {
		// �Ҵ� ���н� ����
		return 0;
	}

	while (1) {
		menuNum = menu(menuList, menuCnt); 	/* �޴���� �� �޴���ȣ �Է� */

		if (menuNum == 0) { break; }
		switch (menuNum) {
		case 1: 			/* ��� ��ǰ ���� */
			listDisplayAppliance(&HomeAuto);
			break;
		case 2: 			/* ��� ��ǰ ������ */
			DisplaySpecificAppliance(&HomeAuto);
			break;
		case 3: 			/* ������ǰ �߰� */
			addAppliance(&HomeAuto);
			break;
		case 4: 			/* ������ǰ ���� */
			deleteAppliance(&HomeAuto);
			break;
		case 5: 			/* ������ǰ ���� */
			controlAppliance(&HomeAuto);
			break;
		case 6: 			/* ����� ��� */
			calculateCost(&HomeAuto);
			break;
		default:
			;
			break;
		}
	}

	deleteListappliance(&HomeAuto);

	return 0;
}