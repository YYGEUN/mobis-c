#include <stdio.h>
#include <stdlib.h>
#include "Appliance.h"
#include "HomeAutomation.h"
#include <time.h>
#include <string.h>
#include "a"

#pragma warning(disable : 4996)

static void myFlush(void) {
	while (getchar() != '\n') {
		;
	}
}

Func_control controlAircon(APP_t* app) {
	
	int n;
	int n2;

	while (1) {
		displayAircon(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n", electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n3 : Select %smode\n4 : Set temperature\n", electromachine[app->Info.type]);
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n▶ 기능 선택 : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 2) {
			app->Info.powerflag = 0;
			app->Info.state1 = -1; // 무동작 대기상태
			if (app->Info.start_H) {
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
			}
			app->Info.start_H = 0; // OFF 명령어 입력시 중복계산 막기
		}
		else if(n == 1)
		{
			if (!app->Info.start_H) // 이미동작중일경우 넘김
			{
				app->Info.start_H = time(&currentTime);
				app->Info.state2 = 25; // 기본값으로 상온 지정
				app->Info.state1 = -1;
				app->Info.powerflag = 1;
			}
		}
		else if (n == 4)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(전원을 켠후 사용해주세요)\n");
				continue;
			}
			while (1) {
				printf("\n--- 제한 온도 (18°C ~ 35°C) ---\n");
				printf("\n▶ 지정할 온도를 입력하세요 : ");
				scanf("%d", &n2);
				myFlush();

				if (n2 >= 18 && n2 <= 35){
					app->Info.state2 = n2;
					break;
				}
				else {
					printf("\n--- 잘못입력하셨습니다 (제한온도 설정 확인) ---\n");
				}
			}
			printf("\n--- Set Temperature %d°C (%s) ---\n",app->Info.state2, app->Info.Mname);
		}
		else if (n == 3)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(전원을 켠후 사용해주세요)\n");
				break;
			}
			while (1) {
				printf("\n==================================================\n");
				printf("\n1 : 제습\n2 : 냉방\n3 : 난방\n");
				printf("\n0 : Exit\n");
				printf("\n==================================================\n");
				printf("\n▶ 에어컨 모드 선택 : ");
				//scanf("%d", &app->Info.state1);
				scanf("%d", &n2);
				myFlush();

				if (n2 == 0) {
					break;
				}

				if (n2 >= 1 && n2 <= 3){
					app->Info.state1 = n2;
					break;
				}
				else {
					printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
				}
			}

			if (app->Info.state1 == 1) {
				printf("\n--- 제습 모드 (%s) ---\n", app->Info.Mname);
			}
			else if (app->Info.state1 == 2) {
				printf("\n--- 냉방 모드 (%s) ---\n", app->Info.Mname);
			}
			if (app->Info.state1 == 3) {
				printf("\n--- 난방 모드 (%s) ---\n", app->Info.Mname);
			}

		}
		else {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		}
	}
	return NULL;
}
Func_control displayAircon(APP_t* app) {
	
	printf("\n");
	printf("==================================================\n");
	printf("제품명 : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("소비 전력량 : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("전원상태 : ON\n");
		
		printf("현재 온도 : %d\n",app->Info.state2);
		
		if (app->Info.state1 == 1) {
			printf("에어콘 모드 : 제습\n");
		}
		else if (app->Info.state1 == 2) {
			printf("에어콘 모드 : 냉방\n");
		}
		else if (app->Info.state1 == 3) {
			printf("에어콘 모드 : 난방\n");
		}
		else if (app->Info.state1 == -1) {
			printf("에어콘 모드 : 송풍(대기중)\n");
		}
		printf("사용시간 : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("전원상태 : OFF\n");
		printf("사용시간 : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}

Func_control controlLight(APP_t* app) {

	int n;
	time_t currentTime;

	while (1) {
		displayLight(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n", electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n");
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n▶ ON/OFF 선택 : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 1)
		{
			if (!app->Info.start_H) // 이미동작중일경우 넘김
			{
				printf("\n--- Light ON (%s) ---\n",app->Info.Mname);
				app->Info.start_H = time(&currentTime);
				app->Info.powerflag = 1;
			}
		}
		else if (n == 2)
		{
			if (app->Info.start_H) {
				printf("\n--- Light OFF (%s) ---\n", app->Info.Mname);
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
				app->Info.powerflag = 0;
			}
			app->Info.start_H = 0; // OFF 명령어 입력시 중복계산 막기
		}
	}
	return NULL;
}
Func_control displayLight(APP_t* app) {

	printf("\n");
	printf("==================================================\n");
	printf("제품명 : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("소비 전력량 : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("전원상태 : ON\n");
		printf("사용시간 : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("전원상태 : OFF\n");
		printf("사용시간 : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}

Func_control controlCooCoo(APP_t* app) {

	int n;
	int n2;

	while (1) {
		displayCooCoo(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n", electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n3 : Select %smode\n",electromachine[app->Info.type]);
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n▶ 기능 선택 : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 2) {
			app->Info.powerflag = 0;
			app->Info.state1 = -1; // 무동작 대기상태
			if (app->Info.start_H) {
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
			}
			app->Info.start_H = 0; // OFF 명령어 입력시 중복계산 막기
		}
		else if (n == 1)
		{
			if (!app->Info.start_H) // 이미동작중일경우 넘김
			{
				app->Info.start_H = time(&currentTime);
				app->Info.powerflag = 1;
				app->Info.state1 = -1;
			}
		}
		else if (n == 3)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(전원을 켠후 사용해주세요)\n");
				continue;
			}

			while (1) {
				printf("\n==================================================\n");
				printf("\n1 : 보온 재가열\n2 : 백미\n3 : 현미\n");
				printf("\n0 : Exit\n");
				printf("\n==================================================\n");
				printf("\n▶ CooCoo 모드 입력 : ");
				//scanf("%d", &app->Info.state1);
				scanf("%d", &n2);
				myFlush();

				if (n2 == 0) {
					break;
				}

				if (n2 >= 1 && n2 <= 3) {
					app->Info.state1 = n2;
					break;
				}
				else {
					printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
				}
			}

			if (app->Info.state1 == 1) {
				printf("\n--- 보온 재가열 모드 (%s)---\n", app->Info.Mname);
			}
			else if (app->Info.state1 == 2) {
				printf("\n--- 백미 모드 (%s)---\n", app->Info.Mname);
			}
			if (app->Info.state1 == 3) {
				printf("\n--- 현미 모드 (%s)---\n", app->Info.Mname);
			}
		}
		else {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		}
	}
	return NULL;
}
Func_control displayCooCoo(APP_t* app) {

	printf("\n");
	printf("==================================================\n");
	printf("제품명 : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("소비 전력량 : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("전원상태 : ON\n");

		if (app->Info.state1 == 1) {
			printf("CooCoo 모드 : 보온재가열\n");
		}
		else if (app->Info.state1 == 2) {
			printf("CooCoo 모드 : 백미\n");
		}
		else if (app->Info.state1 == 3) {
			printf("CooCoo 모드 : 현미\n");
		}
		else if (app->Info.state1 == -1) {
			printf("CooCoo 모드 : 대기중\n");
		}
		printf("사용시간 : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("전원상태 : OFF\n");
		printf("사용시간 : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}

Func_control controlWash(APP_t* app) {
	int n;
	int n2;

	while (1) {
		displayWash(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n",electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n3 : Select %smode\n", electromachine[app->Info.type]);
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n▶ 기능 선택 : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 2) {
			app->Info.powerflag = 0;
			app->Info.state1 = -1; // 무동작 대기상태
			if (app->Info.start_H) {
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
			}
			app->Info.start_H = 0; // OFF 명령어 입력시 중복계산 막기
			//break;
		}
		else if (n == 1)
		{
			if (!app->Info.start_H) // 이미동작중일경우 넘김
			{
				app->Info.start_H = time(&currentTime);
				app->Info.powerflag = 1;
				app->Info.state1 = -1;
			}
			//break;
		}
		else if (n == 3)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(전원을 켠후 사용해주세요)\n");
				break;
			}

			while (1) {
				printf("\n==================================================\n");
				printf("\n1 : 일반세탁\n2 : 빠른세탁\n3 : 건조\n");
				printf("\n0 : Exit\n");
				printf("\n==================================================\n");
				printf("\n▶ Wash 모드 선택 : ");
				//scanf("%d", &app->Info.state1);
				scanf("%d", &n2);
				myFlush();

				if (n2 == 0) {
					break;
				}

				if (n2 >= 1 && n2 <= 3) {
					app->Info.state1 = n2;
					break;
				}
				else {
					printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
				}
			}

			if (app->Info.state1 == 1) {
				printf("\n--- 일반세탁 모드 (%s)---\n", app->Info.Mname);
			}
			else if (app->Info.state1 == 2) {
				printf("\n--- 빠른세탁 모드 (%s)---\n", app->Info.Mname);
			}
			if (app->Info.state1 == 3) {
				printf("\n--- 건조 모드 (%s)---\n", app->Info.Mname);
			}

			//break;
		}
		else {
			printf("\n--- 잘못입력하셨습니다 (목록에서 번호 선택) ---\n");
		}
	}
	return NULL;
}
Func_control displayWash(APP_t* app) {

	printf("\n");
	printf("==================================================\n");
	printf("제품명 : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("소비 전력량 : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("전원상태 : ON\n");

		if (app->Info.state1 == 1) {
			printf("Wash 모드 : 일반세탁\n");
		}
		else if (app->Info.state1 == 2) {
			printf("Wash 모드 : 빠른세탁\n");
		}
		else if (app->Info.state1 == 3) {
			printf("Wash 모드 : 건조\n");
		}
		else if (app->Info.state1 == -1) {
			printf("Wash 모드 : 대기중\n");
		}
		printf("사용시간 : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("전원상태 : OFF\n");
		printf("총 사용시간 : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}


