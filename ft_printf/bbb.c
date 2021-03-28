#include <stdio.h>

int swap(int, int);

int main(void)
{
	int a, b;
	int r;

	a = 5;
	b = 7;
	printf("swap() before : a = %d, b = %d \n", a, b); // 호출 전 a, b 값
	r = swap(a, b); // a와 b의 값 전달
	printf("swap() after : a = %d, b = %d \n", a, b); // 호출 후 a, b 값
	printf ("%d\n", r);
	return 0;
}

int swap (int x, int y)
{
	int temp;
	int ret;

	temp = x;	
	x = y;
	y = temp;
	printf("swap() : x = %d, y = %d\n", x, y);
	ret = x;
	return (ret); //7
}
