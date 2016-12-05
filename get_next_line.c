#include "get_next_line.h"

int prep_buffer(t_rdr *rdr, char **tmp)
{
  if (!rdr->stop)
  {
    *tmp = (char *)ft_memalloc(sizeof(char) * (rdr->tot_buff - (rdr->eol - rdr->buffer + 1)) + 1);
    ft_memmove(*tmp, &rdr->buffer[rdr->eol - rdr->buffer + 1], (rdr->tot_buff - (rdr->eol - rdr->buffer + 1)));
    ft_memdel((void **)&rdr->buffer);
    rdr->char_buff = ft_strlen(*tmp);
    rdr->buffer = (char *)ft_memalloc(sizeof(char) * (rdr->char_buff));
    ft_memmove(rdr->buffer, *tmp, rdr->char_buff);
    ft_memdel((void **)&(*tmp));
    rdr->tot_buff = rdr->char_buff;
  }
  else
  {
    ft_memdel((void **)&rdr->buffer);
    rdr->eol = NULL;
    rdr->tot_buff = 0;
    rdr->char_buff = 0;
    return (1);
  }
  return (1);
}

int read_write(t_rdr *rdr, char **tmp, int *cnt)
{
  while (!(rdr->eol = ft_memchr(rdr->buffer, '\n', rdr->char_buff)))
  {
    *tmp = (char *)ft_memalloc(sizeof(char) * (rdr->char_buff));
    ft_memmove(*tmp, rdr->buffer, rdr->char_buff);
    ft_memdel((void **)&rdr->buffer);
    rdr->buffer = (char *)ft_memalloc(sizeof(char) * (rdr->char_buff + BUFF_SIZE));
    ft_memmove(rdr->buffer, *tmp, rdr->char_buff);
    ft_memdel((void **)&(*tmp));
    if (!(*cnt = read(rdr->fd, rdr->buffer + rdr->char_buff, BUFF_SIZE)))
    {
      rdr->eol = &rdr->buffer[rdr->char_buff];
      rdr->stop = 1;
      break;
    }
    if (*cnt == -1)
      return (-1);
    rdr->char_buff += *cnt;
    rdr->tot_buff += *cnt;
  }
  return (1);
}

int get_next_line(int fd, char **line)
{
  static t_rdr rdr;
  char *tmp;
  int cnt;

  tmp = NULL;
  rdr.fd = fd;
  if (rdr.fd < 0 || !line)
    return (-1);
  if (rdr.stop)
    return (0);
  if (read_write(&rdr, &tmp, &cnt) == -1)
    return (-1);
  if (!cnt && !rdr.tot_buff)
    return (0);
  *line = ft_strnew(rdr.eol - rdr.buffer);
  ft_memmove(*line, rdr.buffer, rdr.eol - rdr.buffer);
  prep_buffer(&rdr, &tmp);
  return (1);
}

// int       main(void)
// {
//   char    *line;
//   int     fd;
//   int     ret;
//   char    *filename;

//   filename = "gnl9_2.txt";
//   fd = open(filename, O_RDONLY);
//   if (fd > 2)
//   {
//     if (close(fd) == 0)
//     {
//       line = NULL;
//       ret = get_next_line(fd, &line);
//       if (ret != -1)
//         printf("-> must have returned '-1' when receiving a closed file descriptor\n");
//       else
//         printf("OK\n");
//     }
//     else
//     {
//       printf("An error occured while closing file descriptor associated with file %s\n", filename);
//       return (0);
//     }
//   }
//   else
//     printf("An error occured while opening file %s\n", filename);
//   return (0);
// }


// int   main(int argc, char **argv)
// {
//   int   fd;
//   char  **line;

//   if (argc != 2)
//     return (0);
//   line = (char **)malloc(sizeof(char) * 5);
//   fd = open(argv[1], O_RDONLY);
//   get_next_line(fd, line);
//   printf("%s---\n", *line);

//   get_next_line(fd, line);
//   printf("%s---\n", *line);

//   get_next_line(fd, line);
//   printf("%s---\n", *line);

//   get_next_line(fd, line);
//   printf("%s---\n", *line);
//   return 0;
// }