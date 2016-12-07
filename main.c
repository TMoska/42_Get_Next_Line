#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// int   main(int argc, char **argv)
// {
// 	int   fd;
// 	int   fd1;
// 	char  **line;
// 	int		i;
// 	int		ret;

// 	i = 0;
// 	(void)argc;
// 	// if (argc != 2)
// 	// 	return (0);
// 	line = (char **)malloc(sizeof(char) * 5);
// 	fd = open(argv[1], O_RDONLY);
	
// 	ret = get_next_line(fd, line);
// 	printf("%s---\n", *line);

// 	ret = get_next_line(fd, line);
// 	printf("%s---\n", *line);
// 	// close(fd);
// 	printf("+======================+\n");
// 	fd1 = open(argv[2], O_RDONLY);
// 	ret = get_next_line(fd1, line);
// 	printf("%s---\n", *line);

// 	ret = get_next_line(fd1, line);
// 	printf("%s---\n", *line);

// 	printf("+======================+\n");
// 	ret = get_next_line(fd, line);
// 	printf("%s---\n", *line);

// 	ret = get_next_line(fd, line);
// 	printf("%s---\n", *line);
// 	close(fd);
// 	close(fd1);
// 	return (0);
// }

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}
