#include  <stdio.h>
struct  _score
{
	char  name[20];
	int   kor, eng, mat;
};
typedef  struct _score ScoreTypedef;
void  struct_prn(ScoreTypedef);

int  main()
{
	ScoreTypedef sd = { "Hong gil dong" , 80, 90, 100 };
	struct_prn(sd);
	getchar();
	return 0;
}
/*------------------------------------------------------------*/
void  struct_prn(ScoreTypedef  x)
{
	printf("%s : %d  %d  %d \n", x.name, x.kor, x.eng, x.mat);
}
