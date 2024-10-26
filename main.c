#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}