#pragma once
#include <time.h>
#define APPLIANCE_MAX_CNT 20
#define TYPENUMBER 4
#define MAX_BUFFER 21

#ifndef APPLIANCE_H_
#define APPLIANCE_H_

enum Electronic{
	AirConditioner,
	Light,
	CooCoo,
	Washingmachine
};

extern time_t currentTime;

extern const char* electromachine[TYPENUMBER];

typedef struct ApplianceINFO {
	char Mname[MAX_BUFFER];
	int type; // 제품종류
	int powerflag; // 전원상태
	int powerconsumtion; // 전력 소비량
	int state1; // 주로 동작 상태
	int state2; // * 에어컨 온도지정
	time_t start_H; 
	time_t use_H;
	void(*control)(ApplianceINFO*);
	void(*display)(ApplianceINFO*);
}APP_INFO_t;

typedef struct Appliance {
	APP_INFO_t Info;
	Appliance* next;
	Appliance* prev;
}APP_t;

typedef struct _list_Appliance {
	APP_t* head;
	APP_t* tail;
	int size;
} list_app_t;

typedef void (*Func_control)(APP_t*);

Func_control controlAircon(APP_t* app);
Func_control controlLight(APP_t* app);
Func_control controlCooCoo(APP_t* app);
Func_control controlWash(APP_t* app);
Func_control displayAircon(APP_t* app);
Func_control displayLight(APP_t* app);
Func_control displayCooCoo(APP_t* app);
Func_control displayWash(APP_t* app);

#endif