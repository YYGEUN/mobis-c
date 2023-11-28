#include  <stdio.h>
typedef  struct
{
	char  name[20];
	int   kor, eng, mat;
}ScoreTypedef;
void  struct_prn(ScoreTypedef  *);
int  main()
{
	ScoreTypedef  ary[2] = { { "Hong gil dong" , 80, 90, 100 } ,
	{ "Lee mong yong" , 75, 85, 95 } };

	struct_prn(ary);
	getchar();
	return 0;
}
/*-----------------------------------------------------------*/
void  struct_prn(ScoreTypedef *p)
{
	int  i;
	for (i = 0; i<2; i++){
		printf("%s : %d %d %d \n", p[i].name, p[i].kor, (p + i)->eng, (p + i)->mat);
	}
}
