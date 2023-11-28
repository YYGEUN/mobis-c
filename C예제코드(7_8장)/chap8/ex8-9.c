#include  <stdio.h>
union  number
{
	char  a ;
	short  b ;
	long  c ;
} abc ;
int  main()
{
	abc.c = (long) 0x12345678 ;
	printf("Long value : %08lx\n" , abc.c ) ;
	printf("short  value : %08hx\n" , abc.b ) ;
	printf("Char value : %08x\n" , abc.a ) ;

	getchar();
	return 0;
}
