#ifndef MENU_H_
#define MENU_H_
#include "LinkedList.h"

int menu(const char **menuStr, int menuCnt);
void mInput(list_t *lp);
void mOutput(list_t *lp);
void mSearch(list_t *lp);
void mDelete(list_t *lp);
void mSort(list_t *lp);

#endif /* MENU_H_ */
