#include<stdio.h>
typedef  struct  _score
{
	char  name[20];
	int   kor, eng, mat;
} ScoreTypedef;
void  struct_prn(char *, int, int, int);
int main()
{
	ScoreTypedef sd = { "Hong gil dong" , 80, 90, 100 };
	struct_prn(sd.name, sd.kor, sd.eng, sd.mat);
	getchar();
	return 0;
}
/*------------------------------------------------------------*/
void  struct_prn(char  *cp, int  k, int  e, int  m)
{
	printf("%s  :  %d  %d  %d \n", cp, k, e, m);
}
