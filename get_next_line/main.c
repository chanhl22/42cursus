#include "get_next_line.h"

int main(void)
{
	char *line;
	int ret;
	int fd;

	fd = open("./test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	//while (1);
	return (0);
}
