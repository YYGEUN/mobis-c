#include <stdio.h>
#include "menu.h"
#include "LinkedList.h"

int main(void) {
	const char *menuList[] = { "입력하기", "출력하기", "검색하기", "다중검색하기", "삭제하기", "정렬하기", "종  료" };

	int menuNum;								/* 메뉴번호 저장 변수 */
	int menuCnt;								/* 메뉴개수 저장 변수 */
	list_t list;								/* 리스트관리 구조체 변수 */
	bool_t bres;
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	bres = createList(&list);					/* 비어 있는 리스트 초기화 */
	if (bres == TRUE) {
		printf("@ list 생성 성공!\n");
	}
	else {
		printf("@ list 생성 실패!\n");
	}

	while (1) {
		menuNum = menu(menuList, menuCnt); 	/* 메뉴출력 및 메뉴번호 입력 */

		if (menuNum == menuCnt) { break; }
		switch (menuNum){
		case 1: 			/* 입력메뉴 실행 */
			mInput(&list);
			break;
		case 2: 			/* 출력메뉴 실행 */
			mOutput(&list);
			break;
		case 3: 			/* 검색메뉴 실행 */
			mSearch(&list);
			break;
		case 4:
			mSearchDuplicate(&list);
			break; 
		case 5: 			/* 삭제메뉴 실행 */
			mDelete(&list);
			break;
		case 6:				/* 정렬메뉴 실행 */
			sortList(&list);
			break;
		default:
			;
			break;
		}
	}
	printf("list내의 데이터 노드의 개수 : %d\n", list.size);
	destoryList(&list);						/* 리스트내의 모든 데이터 삭제 */

	return 0;
}

