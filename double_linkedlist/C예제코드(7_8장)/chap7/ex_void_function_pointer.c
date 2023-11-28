#include <stdio.h>
void showDouble(void *vp);
void showInt(void *vp);
void forEach(void *start, void *end, size_t size, void(*workData)(void *));

int main()
{
	int   x[10] = { 1, 2,3,4,5,6,7,8,9,10 };
	double  y[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	printf("[ x 배열 출력하기 ]\n");
	forEach(x, x + 10, sizeof(int), showInt);

	printf("\n[ y 배열 출력하기 ]\n");
	forEach(y, y + 5, sizeof(double), showDouble);

	getchar();
	return 0;
}

void forEach(void *start, void *end, size_t size, void(*workData)(void *))
{
	while (start != end)
	{
		workData(start);
		start = (char *)start + size;
	}
}

void showDouble(void *vp)
{
	printf("y=%lf\n", *(double *)vp);
}

void showInt(void *vp)
{
	printf("x=%d\n", *(int *)vp);
}
