#include "Appliance.h"

#ifndef HOMEAUTOMATION_H_
#define HOMEAUTOMATION_H_

typedef struct HomeAutomation {
	APP_t appliancearr[APPLIANCE_MAX_CNT];
	list_app_t ListApp[TYPENUMBER];
	int appCnt;
	long long int Cost[TYPENUMBER];
}HomeAuto_t;

//------------------------------------------------------------------- 주 기능 ---------------------------------
int menu(const char** menuList, int menuCnt); /* 메뉴 */
void listDisplayAppliance(HomeAuto_t* HOME); /* 전제품 정보 간단 출력 */
void DisplaySpecificAppliance(HomeAuto_t* HOME); /* 상제 제품정보 출력 */
void addAppliance(HomeAuto_t* HOME); /* 제품 추가  */
void deleteAppliance(HomeAuto_t* HOME); /* 제품 삭제 */
void controlAppliance(HomeAuto_t* HOME); /* 컨트롤 할 제품 선택 */
void calculateCost(HomeAuto_t* HOME); /* 현재시간 기준 사용료 계산 */
//------------------------------------------------------------------- 주 기능 ---------------------------------

//------------------------------------------------------------------- 보조 기능 ---------------------------------
int createListappliance(HomeAuto_t* HOME); /* 연결 리스트 관리체 설정 */
void deleteListappliance(HomeAuto_t* HOME); /* 연결 리스트 관리체 할당 해제 */

void recordInfoAppliance(HomeAuto_t* HOME, APP_INFO_t* appinfo);
void callType(HomeAuto_t* HOME); /* 제품 타입 불러오기 */
void callAppliance(HomeAuto_t* HOME, int n); /* 선택된 타입 제품 불러오기 */
void connectController(APP_t* app, int typenum); /* 각 컨트롤러로 전달 */
int checkname(HomeAuto_t* HOME,const char* name); /* 중복이름 찾기 전제품중 이름은 유니크 해야함 */
int selectType(HomeAuto_t* HOME); /* 제품 Type 지정함수 */
APP_t* selectAppliance(HomeAuto_t* HOME, int n); /* 제품 지정함수 */
//------------------------------------------------------------------- 보조 기능 ---------------------------------

 // ---------------------------------------------------------------- double linked list ---------------------------
int createList(list_app_t* lap);	/* 연결 리스트 관리체 설정 */
void deleteList(HomeAuto_t* HOME,list_app_t* lap); /* 연결 리스트 관리체 할당 해제 */
int addappLast(list_app_t* lap, APP_INFO_t appinfo);  /* tail node 앞에 node 추가(정순 저장) */
int removeApp(HomeAuto_t* HOME,list_app_t* lap, char str[]); /* 이름 받아서 제거 */
APP_t* searchApp(list_app_t* lap, char* name); /* 이름으로 app 찾기 */
int removeApp2(HomeAuto_t* HOME, APP_t* rapp, int n); /* 넘버링 받아서 제거 */
// ---------------------------------------------------------------- double linked list ---------------------------

#endif