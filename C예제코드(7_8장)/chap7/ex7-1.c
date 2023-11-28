#include  <stdio.h>
int main()
{
	char  *cp,  ch = 'a' ;
	int    *ip,  num = 5 ;
	double  *dp,  dnum = 3.14 ;
	cp = &ch ;
	ip = &num ;
	dp = &dnum ;
	printf("cp : %u, *cp : %u Byte\n", sizeof(cp), sizeof(*cp));
	printf("ip : %u, *ip : %u Byte\n", sizeof(ip), sizeof(*ip));
	printf("dp : %u, *dp : %u Byte\n", sizeof(dp), sizeof(*dp));

	getchar();
	return 0;
}
