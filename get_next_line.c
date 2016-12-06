/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:27:38 by tmoska            #+#    #+#             */
/*   Updated: 2016/12/06 00:28:02 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	prep_buff(t_rdr *rdr, char **tmp)
{
	int str_len;

	if (!rdr->stop)
	{
		str_len = (rdr->tot_buff - (rdr->eol - rdr->buff + 1));
		*tmp = (char *)ft_memalloc(str_len + 1);
		ft_memmove(*tmp, &rdr->buff[rdr->eol - rdr->buff + 1], str_len);
		ft_memdel((void **)&rdr->buff);
		rdr->char_buff = ft_strlen(*tmp);
		rdr->buff = (char *)ft_memalloc(sizeof(char) * (rdr->char_buff));
		ft_memmove(rdr->buff, *tmp, rdr->char_buff);
		ft_memdel((void **)&(*tmp));
		rdr->tot_buff = rdr->char_buff;
	}
	else
	{
		ft_memdel((void **)&rdr->buff);
		rdr->eol = NULL;
		rdr->tot_buff = 0;
		rdr->char_buff = 0;
		return (1);
	}
	return (1);
}

int	read_write(t_rdr *rdr, char **tmp, int *cnt)
{
	while (!(rdr->eol = ft_memchr(rdr->buff, '\n', rdr->char_buff)))
	{
		*tmp = (char *)ft_memalloc(rdr->char_buff);
		ft_memmove(*tmp, rdr->buff, rdr->char_buff);
		ft_memdel((void **)&rdr->buff);
		rdr->buff = (char *)ft_memalloc(rdr->char_buff + BUFF_SIZE);
		ft_memmove(rdr->buff, *tmp, rdr->char_buff);
		ft_memdel((void **)&(*tmp));
		if (!(*cnt = read(rdr->fd, rdr->buff + rdr->char_buff, BUFF_SIZE)))
		{
			rdr->eol = &rdr->buff[rdr->char_buff];
			rdr->stop = 1;
			break ;
		}
		if (*cnt == -1)
			return (-1);
		rdr->char_buff += *cnt;
		rdr->tot_buff += *cnt;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_rdr	rdr;
	char			*tmp;
	int				cnt;

	tmp = NULL;
	rdr.fd = fd;
	if (rdr.fd < 0)
	{
		*line = NULL;
		return (-1);
	}
	// if (rdr.stop == 1)
		// return (0);
	// printf("0");
	if (read_write(&rdr, &tmp, &cnt) == -1)
	{
		*line = NULL;
		return (-1);
	}
	if (!cnt && !rdr.tot_buff)
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strnew(rdr.eol - rdr.buff);
	ft_memmove(*line, rdr.buff, rdr.eol - rdr.buff);
	prep_buff(&rdr, &tmp);
	return (1);
}
