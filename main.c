#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*result;

	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	result = get_next_line(fd);
	printf("\\%s", result);
	//result = get_next_line(fd);
	//printf("%s\n", result);
	//result = get_next_line(fd);
	//printf("%s\n", result);
	//free(result);
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}