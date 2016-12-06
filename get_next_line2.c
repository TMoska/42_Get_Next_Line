
int   cleanup_buffer(t_rdr *rdr)
{
  int   i;

  i = 0;
  ft_memmove(rdr->buff, rdr->eol, rdr->eol - rdr->buff)
}

int   get_next_line(int fd, char **line)
{
  static t_rdr  rdr;
  char          *tmp;
  int           cnt;

  rdr.fd = fd;
  if (rdr.fd < 0)
    return (-1);
  if (rdr.buff)
    cleanup_buff(&rdr);
  else
    rdr.buff = (char *)ft_memalloc(BUFF_SIZE);

}