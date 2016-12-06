#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int   main(int argc, char **argv)
{
	int   fd;
	char  **line;
	int		i;
	int		ret;

	i = 0;
	if (argc != 2)
		return (0);
	line = (char **)malloc(sizeof(char) * 5);
	fd = open(argv[1], O_RDONLY);
	while (i++ <= 5)
	{
		ret = get_next_line(fd, line);
		printf("%s---\n", *line);
	}
	return (0);
}
