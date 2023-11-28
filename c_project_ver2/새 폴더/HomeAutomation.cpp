#include <stdio.h>
#include <stdlib.h>
#include "Appliance.h"
#include "HomeAutomation.h"
#include <string.h>
#include <string>
#pragma warning(disable : 4996)

const char* electromachine[TYPENUMBER] = { "AirConditioner","Light","CooCoo","Washingmachine" };
time_t currentTime;

static void myFlush(void) {
	while (getchar() != '\n') {
		;
	}
}

//------------------------------------------------------------------- 주 기능 ---------------------------------

// ------------------------ 메뉴 출력 ------------------------
int menu(const char** menuList, int menuCnt) {
	int i;
	int num;

	num = 0;
	do {
		printf("\n===== 메인 메뉴 ==================================\n\n");
		for (i = 1; i < menuCnt; i++) {
			printf("%d : %s\n", i, menuList[i]);
		}
		printf("\n%d : %s\n", 0, menuList[0]);
		printf("\n==================================================\n");

		printf("\n▶ 메뉴번호 선택 : ");

		scanf("%d", &num);
		
		if (getchar() != '\n') {
			printf("\n--- 잘못입력하셨습니다 (숫자만 입력) ---\n");
			myFlush();
			continue;
		}

		if (num >= 0 && menuCnt > num) {
			break;
		}

		printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");

	} while ((num >= 0 && menuCnt > num));

	return num;
}

// ------------------------ 기본 사항 출력 ------------------------
void listDisplayAppliance(HomeAuto_t* HOME) {

	if (HOME->appCnt == 0) {
		printf("\n--- 등록된 제품이 없습니다 ---\n");
		return;
	}

	APP_t* printapp;

	int num = 0;
	for (int i = 0; i < TYPENUMBER; i++) {
		num += HOME->ListApp[i].size;
	}
	printf("\n==================================================\n");
	printf("\n===== 제품 타입 %d개  / 제품수 %d개 등록됨 =========\n", HOME->appCnt, num);

	for (int i = 0; i < HOME->appCnt; i++)
	{
		int tmp = HOME->appliancearr[i].Info.type;
		int cnt = 1;

		printapp = HOME->ListApp[tmp].head->next;
		printf("\n===== %s =====\n\n", electromachine[printapp->Info.type]);
		while (printapp != HOME->ListApp[tmp].tail) {
			printf("%d번 : %s", cnt, printapp->Info.Mname);
			if (printapp->Info.powerflag == 1) {
				printf(" (ON)\n");
			}
			else
			{
				printf(" (OFF)\n");
			}
			printapp = printapp->next;
			cnt += 1;
		}
	}
	printf("\n==================================================\n");
}

// ------------------------ 자세한 사항 출력 ------------------------
void DisplaySpecificAppliance(HomeAuto_t* HOME) {
	if (HOME->appCnt == 0) {
		printf("\n--- 등록된 제품이 없습니다 ---\n");
		return;
	}

	int n;
	int typenum;
	APP_t* displayapp;

	while (1) {

		n = selectType(HOME);
		if (n == -1) {
			return;
		}

		typenum = HOME->appliancearr[n].Info.type;

		displayapp = selectAppliance(HOME, n);

		if (displayapp == NULL) {
			return;
		}

		switch (typenum)
		{
		case 0:
			displayAircon(displayapp);
			break;
		case 1:
			displayLight(displayapp);
			break;
		case 2:
			displayCooCoo(displayapp);
			break;
		case 3:
			displayWash(displayapp);
			break;
		default:
			break;
		}
	}
}

// ------------------------ 제품 추가 -----------------------------
void addAppliance(HomeAuto_t* HOME) {

	int n = 0;
	int res = 0;
	int num = HOME->appCnt;
	APP_INFO_t* addapp;

	// ----------------------------- 제품 타입 -------------------------------
	while (1) {
		printf("\n==================================================\n\n");
		for (int i = 0; i < TYPENUMBER; i++)
		{
			printf("%d : %s\n", i + 1, electromachine[i]);
		}
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n▶ 제품타입 선택 : ");
		res = scanf("%d", &n);
		myFlush();

		if (res == 0) {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
			continue;
		}

		if (n == 0) {
			break;
		}
		n -= 1; //인덱스 맞춤

		if (n >= 0 && n < TYPENUMBER) {
			if (HOME->ListApp[n].size == 0) {
				printf("\n--- 신규 등록을 진행합니다 ---\n");
				addapp = &HOME->appliancearr[num].Info;
				addapp->type = n;
				recordInfoAppliance(HOME, addapp);
				if (strcmp(addapp->Mname, "\0") == 0) {
					return;
				}

				addappLast(&HOME->ListApp[n], *addapp);
				HOME->appCnt += 1;
			}
			else {
				printf("\n--- 추가 등록을 진행합니다 ---\n");
				addapp = (APP_INFO_t*)malloc(sizeof(APP_INFO_t));
				if (addapp == NULL) {
					printf("\n--- 메모리 부족 - 등록불가 ---\n");
					return;
				}
				addapp->type = n;
				recordInfoAppliance(HOME, addapp);
				if (strcmp(addapp->Mname, "\0") == 0) {
					free(addapp);
					return;
				}

				addappLast(&HOME->ListApp[n], *addapp);
				free(addapp);
			}
			break;
		}
		else {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		}
	}
	return;
}

// ------------------------ 제품 삭제 -----------------------------
void deleteAppliance(HomeAuto_t* HOME) {

	if (HOME->appCnt == 0) {
		printf("\n--- 등록된제품이 없습니다 ---\n");
		return;
	}

	int n;
	int typenum;
	APP_t* deleteapp;

	n = selectType(HOME);
	if (n == -1) {
		return;
	}

	typenum = HOME->appliancearr[n].Info.type;

	deleteapp = selectAppliance(HOME, n);
	if (deleteapp == NULL) {
		return;
	}

	removeApp2(HOME, deleteapp, n);
}

// ------------------------ 제품 제어 선택 -----------------------------
void controlAppliance(HomeAuto_t* HOME) {

	if (HOME->appCnt == 0) {
		printf("\n--- 등록된제품이 없습니다 ---\n");
		return;
	}

	int n, typenum;

	APP_t* controlapp;

	while (1) {

		n = selectType(HOME);
		if (n == -1) {
			return;
		}

		typenum = HOME->appliancearr[n].Info.type;

		controlapp = selectAppliance(HOME, n);
		if (controlapp == NULL) {
			return;
		}

		connectController(controlapp, typenum);
		}
	}

// ------------------------ 코스트 계산 -----------------------------
void calculateCost(HomeAuto_t* HOME) {
	APP_t* tp;
	long long int tmpcost;
	long long int totalcost = 0;

	printf("\n===== 사용 요금 ==================================\n\n");
	for (int i = 0; i < TYPENUMBER; i++) {
		tp = HOME->ListApp[i].head->next;
		if (tp == HOME->ListApp[i].tail) {
			printf("%s 사용료 : %.3lf원\n", electromachine[i], HOME->Cost[i]/ (float)1000);
			totalcost += HOME->Cost[i];
			continue;
		}

		tmpcost = HOME->Cost[i];
		while (tp != HOME->ListApp[i].tail) {
			if (tp->Info.start_H != 0) {
				tmpcost += (tp->Info.powerconsumtion * (time(&currentTime) - tp->Info.start_H));
			}
			tp = tp->next;
		}
		totalcost += tmpcost;
		printf("%s 사용료 : %.3lf원\n", electromachine[i], tmpcost/(float)1000);
	}
	printf("\n총 사용료 : %.3lf원\n", totalcost/ (float)1000);
	printf("\n==================================================\n");
}

//------------------------------------------------------------------- 주 기능 ---------------------------------



//------------------------------------------------------------------- 보조기능 기능 ----------------------------

// ------------------------ 프로그램 실행 전 -----------------------------
int createListappliance(HomeAuto_t* HOME)  // 프로그램 실행전 실시 (동적할당)
{
	printf("\n===== 시스템 로딩중 ==============================\n");

	for (int i = 0; i < TYPENUMBER; i++) {
		if (createList(&HOME->ListApp[i]) == 0) {
			for (int j = 0; j < i; j++) {
				deleteList(HOME,&HOME->ListApp[i]);
			}
			printf("\n===== 로딩에 실패하였습니다. 프로그램을 종료합니다.\n");
			return 0;
		}
	}
	printf("===== 시스템 로딩성공 ============================\n");
	return 1;
}

// ------------------------ 프로그램 실행 종료시 -----------------------------
void deleteListappliance(HomeAuto_t* HOME) // 프로그램 실행종료시 실시 (동적할당 해제)
{
	calculateCost(HOME);
	for (int i = 0; i < TYPENUMBER; i++) {
		deleteList(HOME, &HOME->ListApp[i]);
	}

	printf("\n===== 시스템 셧다운 ==============================\n");
}

// ------------------------ 제품 목록 불러오기 ------------------------
void callType(HomeAuto_t* HOME) {
	printf("\n===== 제품 타입 ==================================\n\n");
	for (int i = 0; i < HOME->appCnt; i++)
	{
		printf("%d : %s\n", i + 1, electromachine[HOME->appliancearr[i].Info.type]);
	}
	printf("\n0 : Exit\n");
	printf("\n==================================================\n");
}

// ------------------------ 제품 목록 불러오기 ------------------------
void callAppliance(HomeAuto_t* HOME,int n){

	APP_t* callapp;
	int cnt = 1;

	callapp = HOME->ListApp[HOME->appliancearr[n].Info.type].head->next;
	printf("\n==================================================\n");
	printf("\n===== (%s) 제품 목록 =====\n\n", electromachine[callapp->Info.type]);
	while (callapp != HOME->ListApp[HOME->appliancearr[n].Info.type].tail)
	{
		printf("%d : %s\n", cnt, callapp->Info.Mname);
		callapp = callapp->next;
		cnt += 1;
	}
	printf("\n0 : Exit\n");
	printf("\n==================================================\n");
}

// ------------------------ 등록된 제품 타입 선택 함수 ------------------------
int selectType(HomeAuto_t* HOME) {
	int n = -1;

	while (1) {

		callType(HOME);

		printf("\n▶ 제품타입 선택 : ");
		scanf("%d", &n);

		if (getchar() != '\n') {
			printf("\n--- 숫자만 입력하세요 (목록에서 번호 선택) ---\n");
			myFlush();
			continue;
		}

		if (n == 0) {
			printf("\n--- 취소되었습니다 (타입선택) ---\n");
			return -1;
		}

		n -= 1; //인덱스 맞춤

		if (n >= 0 && n < HOME->appCnt) {
			//callAppliance(HOME, n);
			break;
		}
		else {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		}
		printf("\n==================================================\n");
	}

	return n;
}

// ------------------------ 등록된 제품 선택 함수 ------------------------
APP_t* selectAppliance(HomeAuto_t* HOME, int n) {
	int n2;
	APP_t* selectApp;

	while (1)
	{
		callAppliance(HOME, n);
		printf("\n▶ 제품 선택 : ");
		scanf("%d", &n2);

		if (getchar() != '\n') {
			printf("\n--- 숫자만 입력하세요 (목록에서 번호 선택) ---\n");
			myFlush();
			continue;
		}

		if (n2 == 0) {
			printf("\n--- 취소되었습니다. (등록제품 선택) ---\n");
			return NULL;
		}

		n2 -= 1; //인덱스 맞춤

		int typenum = HOME->appliancearr[n].Info.type;
		if (n2 >= 0 && n2 < HOME->ListApp[typenum].size) {

			selectApp = HOME->ListApp[HOME->appliancearr[n].Info.type].head->next;
			for (int i = 0; i < n2; i++) {
				selectApp = selectApp->next;
			}
			return selectApp;
		}
		else {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		}
	}
}

// ------------------------ 중복 이름 검색 ------------------------
int checkname(HomeAuto_t* HOME,const char* name) {

	if (HOME->appCnt == 0) {
		return 1;
	}

	APP_t* findname;

	for (int i = 0; i < HOME->appCnt; i++) {
		int typenum = HOME->appliancearr[i].Info.type;
		findname = HOME->ListApp[typenum].head->next;
		while (findname != HOME->ListApp[typenum].tail)
		{
			if (!strcmp(findname->Info.Mname, name)) {
				printf("\n%s (으)로 등록된 제품이 있습니다 (제품 타입 : %s)\n", name, electromachine[findname->Info.type]);
				return 0;
			}
			findname = findname->next;
		}
	}

	return 1;
}

// ------------------------ appliance 정보 입력 ------------------------
void recordInfoAppliance(HomeAuto_t* HOME,APP_INFO_t* appinfo) {

	int res = 0;
	int n;
	char* imsi = (char*)malloc(sizeof(char) * MAX_BUFFER);
	// ----------------------------- 이름 입력 ------------------------------- 
	while (1) {
		printf("--- 20자 이내 영문 및 숫자만 가능합니다 --- (0 : Exit)\n");
		printf("\n▶ 제품 이름입력 : ");

		fgets(imsi,MAX_BUFFER,stdin);

		imsi[strlen(imsi) - 1] = '\0';

		if (strcmp(imsi, "0") == 0) {
			strcpy(appinfo->Mname, "\0"); // 초기화
			return;
		}

		int cnt = 0;
		int bcnt = strlen(imsi);
		while (imsi[cnt] == ' ') {
			if (bcnt-1 == cnt) {
				break;
			}
			cnt++;
		}
		while (imsi[bcnt-1] == ' ') {
			if (bcnt == cnt) {
				break;
			}
			bcnt -= 1;
		}
		
		if (bcnt - cnt != strlen(imsi)) {
			printf("\n--- 잘못입력하셨습니다 (이름 앞뒤 공란 불가) ---\n\n");
			continue;
		}

		else if (strcmp(imsi, "") == 0 || strcmp(imsi, " ") == 0) {
			printf("\n--- 잘못입력하셨습니다 (공란 불가) ---\n");
			continue; // 엔터만 쳤을때 재로드
		}

		if (checkname(HOME, imsi)) {
			strcpy(appinfo->Mname, imsi);
			break;
		}
	}

	free(imsi);

	// ----------------------------- 전원 상태(초기 꺼짐) -------------------------------

	appinfo->powerflag = 0;

	// ----------------------------- 소비 전력 -------------------------------
	while (res == 0) {
		printf("▶ 소비전력 입력(mW/s) : ");
		res = scanf("%d", &n);

		if (getchar() != '\n') {
			printf("\n--- 잘못입력하셨습니다 (숫자만 입력) ---\n");
			res = 0;
			myFlush();
			continue;
		}

		if (n == 0) {
			strcpy(appinfo->Mname, "\0"); // 초기화
			return;
		}
	}
	appinfo->powerconsumtion = n;
	res = 0;

	// ----------------------------- 제품 동작 상태(기본상태) -------------------------------
	appinfo->state1 = -1;
	appinfo->state2 = -1;

	// ----------------------------- 시간 -------------------------------
	appinfo->start_H = 0;
	appinfo->use_H = 0;

	printf("\n--- 제품 등록 성공 ---\n\n");
}

// ------------------------ 제품 제어 함수 연결 -----------------------------
void connectController(APP_t* app,int typenum) {
	switch (typenum) /* 등록 가전제품 타입 지정 */
	{
	case 0:
		controlAircon(app);
		break;
	case 1:
		controlLight(app);
		break;
	case 2:
		controlCooCoo(app);
		break;
	case 3:
		controlWash(app);
		break;
	default:
		printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		break;
	}
}

//------------------------------------------------------------------- 보조기능 기능 ----------------------------



// // ---------------------------------------------------------------- double linked list ---------------------------
int createList(list_app_t* lap) {

	if (lap == NULL) {
		return 0;
	}
	lap->head = (APP_t*)malloc(sizeof(APP_t));  // head node 할당 
	if (lap->head == NULL) {
		return 0;
	}
	lap->tail = (APP_t*)malloc(sizeof(APP_t)); // tail node 할당
	if (lap->tail == NULL) {
		free(lap->head); // 이미 head가 동적할당 받음 (메모리누수방지)
		return 0;
	}

	lap->head->Info.use_H = 0;

	lap->head->next = lap->tail;
	lap->head->prev = lap->head;
	lap->tail->next = lap->tail;
	lap->tail->prev = lap->head;
	lap->size = 0;

	return 1;
}
void deleteList(HomeAuto_t* HOME,list_app_t* lap) {
	APP_t* np, * tp;
	if (lap == NULL) {
		return;
	}
	tp = lap->head->next;
	while (tp != lap->tail) {
		//if (tp->Info.powerflag == 1) {
		//	tp->Info.use_H += time(&currentTime) - tp->Info.start_H;
		//}
		HOME->Cost[tp->Info.type] += tp->Info.use_H * tp->Info.powerconsumtion;
		np = tp->next;
		free(tp);
		tp = np;
	}

	free(lap->head);
	free(lap->tail);
	lap->head = lap->tail = NULL;
	lap->size = 0;
	return;
}
int addappLast(list_app_t* lap, APP_INFO_t appinfo) {
	Appliance* addapp;
	if (lap == NULL) {
		return 0;
	}
	addapp = (Appliance*)malloc(sizeof(Appliance));
	if (addapp == NULL) {
		return 0;
	}

	addapp->Info = appinfo;

	addapp->prev = lap->tail->prev;
	addapp->next = lap->tail;
	lap->tail->prev->next = addapp;
	lap->tail->prev = addapp;

	lap->size++;
	return 1;
}
// 이름으로 제품 삭제 검색할때
APP_t* searchApp(list_app_t* lap, char name[]) {
	if (lap == NULL) {
		return NULL;
	}

	APP_t* sapp;
	sapp = lap->head->next;
	while (sapp != lap->tail)
	{
		if (!strcmp(sapp->Info.Mname, name))
		{
			return sapp;
		}
		sapp = sapp->next;
	}

	return NULL;
}
int removeApp(HomeAuto_t* HOME,list_app_t* lap, char str[]) {
	APP_t* rapp;

	if (lap == NULL) {
		return 0;
	}

	rapp = searchApp(lap, str);

	if (rapp != NULL)
	{
		if (rapp->Info.powerflag == 1) {
			rapp->Info.use_H += time(&currentTime) - rapp->Info.start_H;
		}
		HOME->Cost[rapp->Info.type] += rapp->Info.use_H * rapp->Info.powerconsumtion;
		rapp->next->prev = rapp->prev;
		rapp->prev->next = rapp->next;
		free(rapp);
		lap->size -= 1;
		return 1;
	}

	return 0;
}

// 제품 타입과 번호선택으로 제품 삭제할때
int removeApp2(HomeAuto_t* HOME, APP_t* rapp,int n) {
	if (rapp != NULL)
	{
		if (rapp->Info.powerflag == 1) {
			rapp->Info.use_H += time(&currentTime) - rapp->Info.start_H;
		}
		HOME->Cost[rapp->Info.type] += rapp->Info.use_H * rapp->Info.powerconsumtion;
		HOME->ListApp[rapp->Info.type].size -= 1;

		if (HOME->ListApp[rapp->Info.type].size == 0) {
			HOME->appCnt -= 1;
			for (int i = n; i < HOME->appCnt; i++) {
				HOME->appliancearr[i] = HOME->appliancearr[i + 1];
			}
		}

		rapp->next->prev = rapp->prev;
		rapp->prev->next = rapp->next;

		free(rapp);

		return 1;
	}
	return 0;
}
// // ---------------------------------------------------------------- double linked list ---------------------------