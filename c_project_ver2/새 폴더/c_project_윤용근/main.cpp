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
	const char* menuList[] = {"홈오토 종료","등록 제품개요", "제품 상세정보" ,"가전제품 추가", "가전제품 삭제" ,"가전제품 제어", "현재 사용료 계산"};
	int menuNum;								/* 메뉴번호 저장 변수 */
	int menuCnt;								/* 메뉴개수 저장 변수 */
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	//const char* electromachine[TYPENUMBER] = { "AirConditioner","Light","CooCoo","Washingmachine" };

	HomeAuto.appCnt = 0; // 혹시몰라 초기값 지정


	if (createListappliance(&HomeAuto) == 0) {
		// 할당 실패시 종료
		return 0;
	}

	while (1) {
		menuNum = menu(menuList, menuCnt); 	/* 메뉴출력 및 메뉴번호 입력 */

		if (menuNum == 0) { break; }
		switch (menuNum) {
		case 1: 			/* 등록 제품 개요 */
			listDisplayAppliance(&HomeAuto);
			break;
		case 2: 			/* 등록 제품 상세정보 */
			DisplaySpecificAppliance(&HomeAuto);
			break;
		case 3: 			/* 가전제품 추가 */
			addAppliance(&HomeAuto);
			break;
		case 4: 			/* 가전제품 삭제 */
			deleteAppliance(&HomeAuto);
			break;
		case 5: 			/* 가전제품 제어 */
			controlAppliance(&HomeAuto);
			break;
		case 6: 			/* 사용요금 계산 */
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