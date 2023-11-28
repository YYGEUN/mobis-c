#include  <stdio.h>
int  main()
{
	int  ary[5] = {10,20,30,40,50} ;
	int  *p, i ;
	p = ary ;
	for(i=0 ; i<5 ; i++) printf("%6d", ary[i]) ;
	printf("\n\n");
	for(i=0 ; i<5 ; i++) printf("%6d", *(p+i)) ;
	printf("\n\n");
	for(i=0 ; i<5 ; i++) printf("%6d", *(ary+i)) ;
	printf("\n\n");
	for(i=0 ; i<5 ; i++) printf("%6d", p[i]) ;
	printf("\n\n");

	getchar();
	return 0;
}
