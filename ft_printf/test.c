#include <stdio.h>
#include <stdarg.h>

int printNumbers(int args, ...)
{
    va_list ap; 
	int num = 0;

    va_start(ap, args);  
    for (int i = 0; i < args; i++) 
    {
        num = va_arg(ap, int);                             
        printf("%d ", num); 
    }
    va_end(ap); 

    printf("\n");
	return (num);
}

int main()
{
	int num = 123;
	printf("%d\n",num);
	printf("again");

    printf("%d\n",printNumbers(1, 10)); 
    printNumbers(2, 10, 20);
    printNumbers(3, 10, 20, 30);
    printNumbers(4, 10, 20, 30, 40);

    return 0;
}
