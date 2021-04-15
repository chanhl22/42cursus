#include <stdio.h>
#include <stdarg.h>

int		length_of_int(int num)
{
		int len;

		len = (num <= 0) ? 1 : 0;
		while (num != 0)
		{
			num = num / 10;
			len++;
		}
		return (len);
}

int main()
{
	int n = -5;
	int len;
	len = length_of_int(n);

	printf("%d", len);

    return 0;
}
