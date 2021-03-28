#include <stdio.h>

int main(){
	int num = 123;
	int size;

	size = printf("%d\n",num);
	printf("%d",size);

	printf("\n-----\n");

	printf("%-7d\n", 12345);
	//printf("%5.-2d", 9);
	printf("%5.*d\n",-2 , 9);
	//printf("%5.*d", -2, 9);
	printf("%.d\n", 12345);
	
	printf("\n-----\n");

	printf("[%.0d]\n", 0);
	printf("%.d\n", 0);
	printf("%.d\n", 1);
	printf("[%.*d]\n",0 ,0);

}
