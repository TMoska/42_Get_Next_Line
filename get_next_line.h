#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 32

typedef struct  s_rdr
{
  char          *buffer;
  char          *eol;
  int           tot_buff;
  int           char_buff;
  int           stop;
  int           fd;
}               t_rdr;

int get_next_line(int fd, char **line);

#endif