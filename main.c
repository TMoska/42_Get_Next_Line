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
	(void)argc;
	// if (argc != 2)
	// 	return (0);
	line = (char **)malloc(sizeof(char) * 5);
	fd = open(argv[1], O_RDONLY);
	while (i++ <= 4)
	{
		ret = get_next_line(fd, line);
		printf("%s---\n", *line);
	}
	close(fd);
	printf("+======================+\n");
	fd = open(argv[2], O_RDONLY);
	while (i++ <= 4)
	{
		ret = get_next_line(fd, line);
		printf("%s---\n", *line);
	}
	close(fd);
	return (0);
}

// int				main(void)
// {
// 	char		*line;
// 	int			fd;
// 	int			ret;
// 	int			count_lines;
// 	char		*filename;
// 	int			errors;

// 	filename = "gnl1_1.txt";
// 	fd = open(filename, O_RDONLY);
// 	if (fd > 2)
// 	{
// 		count_lines = 0;
// 		errors = 0;
// 		line = NULL;
// 		while ((ret = get_next_line(fd, &line)) > 0)
// 		{
// 			if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
// 				errors++;
// 			if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
// 				errors++;
// 			if (count_lines == 2 && strcmp(line, "edcba0987654321") != 0)
// 				errors++;
// 			if (count_lines == 3 && strcmp(line, "tsrqponmlkjihgf") != 0)
// 				errors++;
// 			count_lines++;
// 			if (count_lines > 50)
// 				break ;
// 		}
// 		close(fd);
// 		if (count_lines != 4)
// 			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
// 		if (errors > 0)
// 			printf("-> must have read \"1234567890abcde\", \"fghijklmnopqrst\", \"edcba0987654321\" and \"tsrqponmlkjihgf\"\n");
// 		if (count_lines == 4 && errors == 0)
// 			printf("OK\n");
// 	}
// 	else
// 		printf("An error occured while opening file %s\n", filename);
// 	return (0);
// }
