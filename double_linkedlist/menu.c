#include <stdio.h>
#include "menu.h"
#pragma warning(disable : 4996)
/*----------------------------------------------------------------------------------
Function name	: myflush - 입력 버퍼 내의 모든 데이터 지우는 함수
Parameters		: 없음
Returns			: 없음
----------------------------------------------------------------------------------*/
static void myFlush(void) {
	while (getchar() != '\n') {
		;
	}
}

/*----------------------------------------------------------------------------------
Function name	: menu
Parameters		: mList - 메뉴 목록 배열
				  menuCnt - 메뉴 개수
Returns			: 사용자 선택한 메뉴번호
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
		printf("메뉴번호입력 : ");
		res = scanf("%d", &num);
		myFlush();
		if (res != 1) {
			printf("잘못 입력하였습니다.\n");
		}
	} while ((num < 1) || (num > menuCnt));

	return num;
}

/*----------------------------------------------------------------------------------
Function name	: mInput - 입력 메뉴 처리 함수
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void mInput(list_t *lp) {
	int inData;
	int res;  /* scanf()함수의 리턴 값 저장 */
	bool_t bres;

	printf("\n[ 입력하기 메뉴 ]\n\n");

	while (1) {
		printf("# 정수를 입력하세요(문자 입력시 종료) : ");
		res = scanf("%d", &inData);	/* scanf()함수의 리턴 값 : 정수 입력 시 1, 문자 입력 시 0리턴 됨*/

		if (res == 0) {	/* 문자 입력 시 종료 */
			myFlush();
			break;
		}

		bres = addLast(lp, inData);	/* tail 노드 앞에 데이터 추가  */
		if (bres == TRUE)
			printf("@ 데이터 추가 성공!\n");
		else
			printf("@ 데이터 추가 실패!\n");
	}
	return;
}

/*----------------------------------------------------------------------------------
Function name	: mOutput - 출력 메뉴 처리 함수
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void mOutput(list_t *lp) {
	displayList(lp);
}

/*----------------------------------------------------------------------------------
Function name	: mSearch - 검색 메뉴 처리 함수
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void mSearch(list_t * lp) {
	int sData;
	node_t *resp;		/* 검색된 노드의 시작주소 저장 */
	int res;			/* scanf()함수의 리턴 값 저장 */

	printf("\n[ 검색하기 메뉴 ]\n\n");
	while (1) {
		printf("# 찾을 데이터를 입력하세요(문자 입력 시 종료) : ");
		res = scanf("%d", &sData);	/* scanf()함수의 리턴 값 : 정수 입력 시 1, 문자 입력 시 0리턴 됨*/

		if (res == 0) {				/* 문자 입력 시 종료 */
			myFlush();
			break;
		}
		else {
			;
		}

		resp = searchNode(lp, sData);
		if (resp != NULL) {	/* 데이터를 찾았으면 */
			printf("@ 검색 데이터 존재!\n");
		}
		else {				/* 데이터를 못찾았으면 */
			printf("@ 검색 데이터 존재하지 않음!\n");
		}
	}
	return;
}

/*----------------------------------------------------------------------------------
Function name	: mDelete - 삭제 메뉴 처리 함수
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void mDelete(list_t * lp) {
	int delData;
	int res;							/* scanf()함수의 리턴 값 저장 */
	bool_t bres;

	printf("\n[ 삭제하기 메뉴 ]\n\n");
	while (1) {
		printf("# 삭제할 데이터를 입력하세요(문자 입력 시 종료) : ");
		res = scanf("%d", &delData);	/* scanf()함수의 리턴 값 : 정수 입력 시 1, 문자 입력 시 0리턴 됨*/

		if (res == 0) {					/* 문자 입력 시 종료 */
			myFlush();
			break;
		}
		else {
			;
		}

		bres = removeNode(lp, delData);
		if (bres == TRUE) {
			printf("@ 삭제 성공!\n");
		}
		else {
			printf("@ 삭제 실패!\n");
		}
	}
	return;
}

/*----------------------------------------------------------------------------------
Function name	: mDestroy - 전체 삭제 메뉴 처리 함수
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void mDestroy(list_t* lp) {
	destoryList(lp);
	printf("\n[ 전체 삭제 완료 ]\n\n");
	return;
}

/*----------------------------------------------------------------------------------
Function name	: mDestroy - 전체 삭제 메뉴 처리 함수
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void mSort(list_t* lp) {
	sortList(lp);
	printf("\n[ 정렬 완료 ]\n\n");
	return;
}

void mSearchduplicate(list_t* lp) {
	int sData;
	node_t* resp;		/* 검색된 노드의 시작주소 저장 */
	int res;			/* scanf()함수의 리턴 값 저장 */
	node_t** d2resp;
	int cnt=0;

	printf("\n[ 중복검색하기 메뉴 ]\n\n");
	while (1) {
		printf("# 찾을 데이터를 입력하세요(문자 입력 시 종료) : ");
		res = scanf("%d", &sData);	/* scanf()함수의 리턴 값 : 정수 입력 시 1, 문자 입력 시 0리턴 됨*/

		if (res == 0) {				/* 문자 입력 시 종료 */
			myFlush();
			break;
		}
		else {
			;
		}

		d2resp = searchDupNode(lp,sData,&cnt);
		if (d2resp != NULL) {	/* 데이터를 찾았으면 */
			printf("%d   %p\n", d2resp[0]->data, d2resp[0]);
			printf("%d 개 있습니다\n",cnt);
			printf("bbb");
			printf("%d   %p\n", d2resp[0]->data, d2resp[0]);
			for (int i = 0; i < cnt; i++)
			{
				printf("%d   %p\n", d2resp[i]->data, d2resp[i]);
			}
			free(d2resp);
			d2resp = NULL;
			cnt = 0;
		}
		else {				/* 데이터를 못찾았으면 */
			printf("@ 검색 데이터 존재하지 않음!\n");
		}
	}
	return;
}