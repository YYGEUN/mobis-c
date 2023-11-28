#include<stdio.h>
void menuDisplay1(const char **menuPtr, size_t menuCnt);
void menuDisplay2(char(*menuPtr)[10], size_t menuCnt);

int main()
{
	const char *ptrMenu[] = { "insert", "output","search", "quit" };
	char aryMenu[][10] = { "INSERT", "OUTPUT","SEARCH", "QUIT" };

	menuDisplay1(ptrMenu, sizeof(ptrMenu) / sizeof(ptrMenu[0]));
	printf("\n\n");
	menuDisplay2(aryMenu, sizeof(aryMenu) / sizeof(aryMenu[0]));

	getchar();
	return 0;
}
//-------------------------------------------------------------
void menuDisplay1(const char **menuPtr, size_t menuCnt)
{
	size_t i;
	for (i = 0; i<menuCnt; i++) {
		printf("%d. %s\n", i + 1, menuPtr[i]);
	}
	return;
}
//-------------------------------------------------------------
void menuDisplay2(char(*menuPtr)[10], size_t menuCnt)
{
	size_t i;
	for (i = 0; i<menuCnt; i++) {
		printf("%d. %s\n", i + 1, menuPtr[i]);
	}
	return;
}
