#include  <stdio.h>
typedef  struct _score
{
	char  name[20];
	int   kor, eng, mat;
} ScoreTypedef;
void  struct_prn(ScoreTypedef  *);
int  main()
{
	ScoreTypedef sd = { "Hong gil dong", 80, 90, 100 };
	struct_prn(&sd);
	getchar();
	return 0;
}
/*-----------------------------------------------------------*/
void  struct_prn(ScoreTypedef  *p)
{
	printf("%s : %d %d %d\n", p->name, p->kor, p->eng, p->mat);
}
