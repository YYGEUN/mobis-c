#include "Appliance.h"

#ifndef HOMEAUTOMATION_H_
#define HOMEAUTOMATION_H_

typedef struct HomeAutomation {
	APP_t appliancearr[APPLIANCE_MAX_CNT];
	list_app_t ListApp[TYPENUMBER];
	int appCnt;
	long long int Cost[TYPENUMBER];
}HomeAuto_t;

//------------------------------------------------------------------- �� ��� ---------------------------------
int menu(const char** menuList, int menuCnt); /* �޴� */
void listDisplayAppliance(HomeAuto_t* HOME); /* ����ǰ ���� ���� ��� */
void DisplaySpecificAppliance(HomeAuto_t* HOME); /* ���� ��ǰ���� ��� */
void addAppliance(HomeAuto_t* HOME); /* ��ǰ �߰�  */
void deleteAppliance(HomeAuto_t* HOME); /* ��ǰ ���� */
void controlAppliance(HomeAuto_t* HOME); /* ��Ʈ�� �� ��ǰ ���� */
void calculateCost(HomeAuto_t* HOME); /* ����ð� ���� ���� ��� */
//------------------------------------------------------------------- �� ��� ---------------------------------

//------------------------------------------------------------------- ���� ��� ---------------------------------
int createListappliance(HomeAuto_t* HOME); /* ���� ����Ʈ ����ü ���� */
void deleteListappliance(HomeAuto_t* HOME); /* ���� ����Ʈ ����ü �Ҵ� ���� */

void recordInfoAppliance(HomeAuto_t* HOME, APP_INFO_t* appinfo);
void callType(HomeAuto_t* HOME); /* ��ǰ Ÿ�� �ҷ����� */
void callAppliance(HomeAuto_t* HOME, int n); /* ���õ� Ÿ�� ��ǰ �ҷ����� */
void connectController(APP_t* app, int typenum); /* �� ��Ʈ�ѷ��� ���� */
int checkname(HomeAuto_t* HOME,const char* name); /* �ߺ��̸� ã�� ����ǰ�� �̸��� ����ũ �ؾ��� */
int selectType(HomeAuto_t* HOME); /* ��ǰ Type �����Լ� */
APP_t* selectAppliance(HomeAuto_t* HOME, int n); /* ��ǰ �����Լ� */
//------------------------------------------------------------------- ���� ��� ---------------------------------

 // ---------------------------------------------------------------- double linked list ---------------------------
int createList(list_app_t* lap);	/* ���� ����Ʈ ����ü ���� */
void deleteList(HomeAuto_t* HOME,list_app_t* lap); /* ���� ����Ʈ ����ü �Ҵ� ���� */
int addappLast(list_app_t* lap, APP_INFO_t appinfo);  /* tail node �տ� node �߰�(���� ����) */
int removeApp(HomeAuto_t* HOME,list_app_t* lap, char str[]); /* �̸� �޾Ƽ� ���� */
APP_t* searchApp(list_app_t* lap, char* name); /* �̸����� app ã�� */
int removeApp2(HomeAuto_t* HOME, APP_t* rapp, int n); /* �ѹ��� �޾Ƽ� ���� */
// ---------------------------------------------------------------- double linked list ---------------------------

#endif