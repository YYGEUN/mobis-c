#include<stdio.h>
typedef void (*func_t)(void);	/* �Լ� �������� ���������� */
void vegetable(), fruit(), grain();
func_t getGroup(int);			/* �Լ� �����͸� �����ϴ� �Լ� ����� */
int main()
{
	int menu;
	void (*fptr)(void) = NULL;
	while(1)
	{
		printf("1. vegetable/ 2. fruit / 3. grain / 4. quit : ");
		scanf("%d", &menu);
		if(menu==4){ break; }
		fptr = getGroup(menu);	/* menu�� ���� �Լ� ������ �� ���� �ޱ� */
		if(fptr != NULL) { fptr(); }
	}

	getchar(); getchar();
	return 0;
}
func_t getGroup(int menu)  /* �޴���ȣ�� �ش��ϴ� �Լ��� �����ּҸ� �����ϴ� �Լ�*/
/* void (*)(void) getGroup(int menu)  ? �̷� ������ ������ ���� �߻� */
/* void (*getGroup(int menu))(void)  �� ǥ���� ���� */
{
	switch(menu)
	{
	case 1 : return vegetable;
	case 2 : return fruit;
	case 3 : return grain;
	}
	return NULL;
}
void vegetable()
{
	const char *vegetableName[] = {"celery", "cucumber", "potato"};
	size_t i;
	for(i=0; i< sizeof(vegetableName)/sizeof(vegetableName[0]); i++)
	{
		printf("[%d] %s\n", i+1, vegetableName[i]);
	}
}
void fruit()
{
	const char *fruitName[] = {"grape", "kiwi", "strawberry", "banana", "orange"};
	size_t i;
	for(i=0; i< sizeof(fruitName)/sizeof(fruitName[0]); i++)
	{
		printf("[%d] %s\n", i+1, fruitName[i]);
	}
}
void grain()
{
	const char *grainName[] = {"rice", "bean", "oats", "corn"};
	size_t i;
	for(i=0; i< sizeof(grainName)/sizeof(grainName[0]); i++)
	{
		printf("[%d] %s\n", i+1, grainName[i]);
	}
}
