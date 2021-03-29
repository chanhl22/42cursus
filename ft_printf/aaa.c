#include <stdio.h>

int main(){
	printf("[%.3d]\n", 1234);
	printf("[%.3d]\n", 3);

	printf("[%.03d]\n", 1234);
	printf("[%.03d]\n", 3);
	
	printf("[%.3d]\n", 0);
	printf("[%.03d]\n", 0);

	printf("--\n");
	printf("[%-.*d]\n",-3, 0);
	//printf("[%.0*d]\n",3, 0);

	//printf("[%.0*d]\n",3, 123);
	//printf("[%.0*d]\n",3, 3);

	printf("[%-.*d]\n",-3, 1234);
	printf("[%-.*d]\n",-3, 3);

	printf("--\n");
	printf("[%.0d]\n", 3);
	printf("[% .0d]\n", 123);
	//printf("[%. 0d]\n", 3);
	printf("[%0.00d]\n", 3);
	printf("[%-.00d]\n", 123);
	
	printf("--\n");
	printf("[%.d]\n", 123);
	printf("[%6.d]\n", 0);
	//printf("[%. d]\n", 123);
	printf("[%-.06d]\n", 123);
	printf("[%6.0d]\n", 0);
	//printf("[%.-d]\n", 123);

	//printf("[%.-0d]\n", 3);
	//printf("[%.-3d]\n", 123);
	//printf("[%.-3d]\n", 3);
	
	//printf("[%. 3d]\n", 123);
	//printf("[%. 3d]\n", 3);	
	
	//printf("[% .3d]\n", 0);
	//printf("[% .3d]\n", 123);
	//printf("[% .3d]\n", 3);
}
