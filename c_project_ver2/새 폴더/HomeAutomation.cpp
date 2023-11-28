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

//------------------------------------------------------------------- �� ��� ---------------------------------

// ------------------------ �޴� ��� ------------------------
int menu(const char** menuList, int menuCnt) {
	int i;
	int num;

	num = 0;
	do {
		printf("\n===== ���� �޴� ==================================\n\n");
		for (i = 1; i < menuCnt; i++) {
			printf("%d : %s\n", i, menuList[i]);
		}
		printf("\n%d : %s\n", 0, menuList[0]);
		printf("\n==================================================\n");

		printf("\n�� �޴���ȣ ���� : ");

		scanf("%d", &num);
		
		if (getchar() != '\n') {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (���ڸ� �Է�) ---\n");
			myFlush();
			continue;
		}

		if (num >= 0 && menuCnt > num) {
			break;
		}

		printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");

	} while ((num >= 0 && menuCnt > num));

	return num;
}

// ------------------------ �⺻ ���� ��� ------------------------
void listDisplayAppliance(HomeAuto_t* HOME) {

	if (HOME->appCnt == 0) {
		printf("\n--- ��ϵ� ��ǰ�� �����ϴ� ---\n");
		return;
	}

	APP_t* printapp;

	int num = 0;
	for (int i = 0; i < TYPENUMBER; i++) {
		num += HOME->ListApp[i].size;
	}
	printf("\n==================================================\n");
	printf("\n===== ��ǰ Ÿ�� %d��  / ��ǰ�� %d�� ��ϵ� =========\n", HOME->appCnt, num);

	for (int i = 0; i < HOME->appCnt; i++)
	{
		int tmp = HOME->appliancearr[i].Info.type;
		int cnt = 1;

		printapp = HOME->ListApp[tmp].head->next;
		printf("\n===== %s =====\n\n", electromachine[printapp->Info.type]);
		while (printapp != HOME->ListApp[tmp].tail) {
			printf("%d�� : %s", cnt, printapp->Info.Mname);
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

// ------------------------ �ڼ��� ���� ��� ------------------------
void DisplaySpecificAppliance(HomeAuto_t* HOME) {
	if (HOME->appCnt == 0) {
		printf("\n--- ��ϵ� ��ǰ�� �����ϴ� ---\n");
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

// ------------------------ ��ǰ �߰� -----------------------------
void addAppliance(HomeAuto_t* HOME) {

	int n = 0;
	int res = 0;
	int num = HOME->appCnt;
	APP_INFO_t* addapp;

	// ----------------------------- ��ǰ Ÿ�� -------------------------------
	while (1) {
		printf("\n==================================================\n\n");
		for (int i = 0; i < TYPENUMBER; i++)
		{
			printf("%d : %s\n", i + 1, electromachine[i]);
		}
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n�� ��ǰŸ�� ���� : ");
		res = scanf("%d", &n);
		myFlush();

		if (res == 0) {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
			continue;
		}

		if (n == 0) {
			break;
		}
		n -= 1; //�ε��� ����

		if (n >= 0 && n < TYPENUMBER) {
			if (HOME->ListApp[n].size == 0) {
				printf("\n--- �ű� ����� �����մϴ� ---\n");
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
				printf("\n--- �߰� ����� �����մϴ� ---\n");
				addapp = (APP_INFO_t*)malloc(sizeof(APP_INFO_t));
				if (addapp == NULL) {
					printf("\n--- �޸� ���� - ��ϺҰ� ---\n");
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
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		}
	}
	return;
}

// ------------------------ ��ǰ ���� -----------------------------
void deleteAppliance(HomeAuto_t* HOME) {

	if (HOME->appCnt == 0) {
		printf("\n--- ��ϵ���ǰ�� �����ϴ� ---\n");
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

// ------------------------ ��ǰ ���� ���� -----------------------------
void controlAppliance(HomeAuto_t* HOME) {

	if (HOME->appCnt == 0) {
		printf("\n--- ��ϵ���ǰ�� �����ϴ� ---\n");
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

// ------------------------ �ڽ�Ʈ ��� -----------------------------
void calculateCost(HomeAuto_t* HOME) {
	APP_t* tp;
	long long int tmpcost;
	long long int totalcost = 0;

	printf("\n===== ��� ��� ==================================\n\n");
	for (int i = 0; i < TYPENUMBER; i++) {
		tp = HOME->ListApp[i].head->next;
		if (tp == HOME->ListApp[i].tail) {
			printf("%s ���� : %.3lf��\n", electromachine[i], HOME->Cost[i]/ (float)1000);
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
		printf("%s ���� : %.3lf��\n", electromachine[i], tmpcost/(float)1000);
	}
	printf("\n�� ���� : %.3lf��\n", totalcost/ (float)1000);
	printf("\n==================================================\n");
}

//------------------------------------------------------------------- �� ��� ---------------------------------



//------------------------------------------------------------------- ������� ��� ----------------------------

// ------------------------ ���α׷� ���� �� -----------------------------
int createListappliance(HomeAuto_t* HOME)  // ���α׷� ������ �ǽ� (�����Ҵ�)
{
	printf("\n===== �ý��� �ε��� ==============================\n");

	for (int i = 0; i < TYPENUMBER; i++) {
		if (createList(&HOME->ListApp[i]) == 0) {
			for (int j = 0; j < i; j++) {
				deleteList(HOME,&HOME->ListApp[i]);
			}
			printf("\n===== �ε��� �����Ͽ����ϴ�. ���α׷��� �����մϴ�.\n");
			return 0;
		}
	}
	printf("===== �ý��� �ε����� ============================\n");
	return 1;
}

// ------------------------ ���α׷� ���� ����� -----------------------------
void deleteListappliance(HomeAuto_t* HOME) // ���α׷� ��������� �ǽ� (�����Ҵ� ����)
{
	calculateCost(HOME);
	for (int i = 0; i < TYPENUMBER; i++) {
		deleteList(HOME, &HOME->ListApp[i]);
	}

	printf("\n===== �ý��� �˴ٿ� ==============================\n");
}

// ------------------------ ��ǰ ��� �ҷ����� ------------------------
void callType(HomeAuto_t* HOME) {
	printf("\n===== ��ǰ Ÿ�� ==================================\n\n");
	for (int i = 0; i < HOME->appCnt; i++)
	{
		printf("%d : %s\n", i + 1, electromachine[HOME->appliancearr[i].Info.type]);
	}
	printf("\n0 : Exit\n");
	printf("\n==================================================\n");
}

// ------------------------ ��ǰ ��� �ҷ����� ------------------------
void callAppliance(HomeAuto_t* HOME,int n){

	APP_t* callapp;
	int cnt = 1;

	callapp = HOME->ListApp[HOME->appliancearr[n].Info.type].head->next;
	printf("\n==================================================\n");
	printf("\n===== (%s) ��ǰ ��� =====\n\n", electromachine[callapp->Info.type]);
	while (callapp != HOME->ListApp[HOME->appliancearr[n].Info.type].tail)
	{
		printf("%d : %s\n", cnt, callapp->Info.Mname);
		callapp = callapp->next;
		cnt += 1;
	}
	printf("\n0 : Exit\n");
	printf("\n==================================================\n");
}

// ------------------------ ��ϵ� ��ǰ Ÿ�� ���� �Լ� ------------------------
int selectType(HomeAuto_t* HOME) {
	int n = -1;

	while (1) {

		callType(HOME);

		printf("\n�� ��ǰŸ�� ���� : ");
		scanf("%d", &n);

		if (getchar() != '\n') {
			printf("\n--- ���ڸ� �Է��ϼ��� (��Ͽ��� ��ȣ ����) ---\n");
			myFlush();
			continue;
		}

		if (n == 0) {
			printf("\n--- ��ҵǾ����ϴ� (Ÿ�Լ���) ---\n");
			return -1;
		}

		n -= 1; //�ε��� ����

		if (n >= 0 && n < HOME->appCnt) {
			//callAppliance(HOME, n);
			break;
		}
		else {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		}
		printf("\n==================================================\n");
	}

	return n;
}

// ------------------------ ��ϵ� ��ǰ ���� �Լ� ------------------------
APP_t* selectAppliance(HomeAuto_t* HOME, int n) {
	int n2;
	APP_t* selectApp;

	while (1)
	{
		callAppliance(HOME, n);
		printf("\n�� ��ǰ ���� : ");
		scanf("%d", &n2);

		if (getchar() != '\n') {
			printf("\n--- ���ڸ� �Է��ϼ��� (��Ͽ��� ��ȣ ����) ---\n");
			myFlush();
			continue;
		}

		if (n2 == 0) {
			printf("\n--- ��ҵǾ����ϴ�. (�����ǰ ����) ---\n");
			return NULL;
		}

		n2 -= 1; //�ε��� ����

		int typenum = HOME->appliancearr[n].Info.type;
		if (n2 >= 0 && n2 < HOME->ListApp[typenum].size) {

			selectApp = HOME->ListApp[HOME->appliancearr[n].Info.type].head->next;
			for (int i = 0; i < n2; i++) {
				selectApp = selectApp->next;
			}
			return selectApp;
		}
		else {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		}
	}
}

// ------------------------ �ߺ� �̸� �˻� ------------------------
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
				printf("\n%s (��)�� ��ϵ� ��ǰ�� �ֽ��ϴ� (��ǰ Ÿ�� : %s)\n", name, electromachine[findname->Info.type]);
				return 0;
			}
			findname = findname->next;
		}
	}

	return 1;
}

// ------------------------ appliance ���� �Է� ------------------------
void recordInfoAppliance(HomeAuto_t* HOME,APP_INFO_t* appinfo) {

	int res = 0;
	int n;
	char* imsi = (char*)malloc(sizeof(char) * MAX_BUFFER);
	// ----------------------------- �̸� �Է� ------------------------------- 
	while (1) {
		printf("--- 20�� �̳� ���� �� ���ڸ� �����մϴ� --- (0 : Exit)\n");
		printf("\n�� ��ǰ �̸��Է� : ");

		fgets(imsi,MAX_BUFFER,stdin);

		imsi[strlen(imsi) - 1] = '\0';

		if (strcmp(imsi, "0") == 0) {
			strcpy(appinfo->Mname, "\0"); // �ʱ�ȭ
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
			printf("\n--- �߸��Է��ϼ̽��ϴ� (�̸� �յ� ���� �Ұ�) ---\n\n");
			continue;
		}

		else if (strcmp(imsi, "") == 0 || strcmp(imsi, " ") == 0) {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (���� �Ұ�) ---\n");
			continue; // ���͸� ������ ��ε�
		}

		if (checkname(HOME, imsi)) {
			strcpy(appinfo->Mname, imsi);
			break;
		}
	}

	free(imsi);

	// ----------------------------- ���� ����(�ʱ� ����) -------------------------------

	appinfo->powerflag = 0;

	// ----------------------------- �Һ� ���� -------------------------------
	while (res == 0) {
		printf("�� �Һ����� �Է�(mW/s) : ");
		res = scanf("%d", &n);

		if (getchar() != '\n') {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (���ڸ� �Է�) ---\n");
			res = 0;
			myFlush();
			continue;
		}

		if (n == 0) {
			strcpy(appinfo->Mname, "\0"); // �ʱ�ȭ
			return;
		}
	}
	appinfo->powerconsumtion = n;
	res = 0;

	// ----------------------------- ��ǰ ���� ����(�⺻����) -------------------------------
	appinfo->state1 = -1;
	appinfo->state2 = -1;

	// ----------------------------- �ð� -------------------------------
	appinfo->start_H = 0;
	appinfo->use_H = 0;

	printf("\n--- ��ǰ ��� ���� ---\n\n");
}

// ------------------------ ��ǰ ���� �Լ� ���� -----------------------------
void connectController(APP_t* app,int typenum) {
	switch (typenum) /* ��� ������ǰ Ÿ�� ���� */
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
		printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		break;
	}
}

//------------------------------------------------------------------- ������� ��� ----------------------------



// // ---------------------------------------------------------------- double linked list ---------------------------
int createList(list_app_t* lap) {

	if (lap == NULL) {
		return 0;
	}
	lap->head = (APP_t*)malloc(sizeof(APP_t));  // head node �Ҵ� 
	if (lap->head == NULL) {
		return 0;
	}
	lap->tail = (APP_t*)malloc(sizeof(APP_t)); // tail node �Ҵ�
	if (lap->tail == NULL) {
		free(lap->head); // �̹� head�� �����Ҵ� ���� (�޸𸮴�������)
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
// �̸����� ��ǰ ���� �˻��Ҷ�
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

// ��ǰ Ÿ�԰� ��ȣ�������� ��ǰ �����Ҷ�
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