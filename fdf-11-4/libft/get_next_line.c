/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:59:05 by saolivei          #+#    #+#             */
/*   Updated: 2018/10/31 10:13:05 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlnd(const char *s, char c)
{
	size_t	l;

	l = 0; 
	while (s[l] != c)
		l++;
	return (l);
}

static int		ft_last_line(char **line, char **fdarray)
{
	*line = ft_strdup(*fdarray);
	if (*fdarray)
		ft_strdel(fdarray);
	return (1);
}

static int		ft_get_line(char **line, char *buf, char **fdarray)
{
	char	*tmp;
	int		len;

	if (buf != NULL)
	{
		tmp = ft_strjoin(*fdarray, buf);
		ft_strdel(fdarray);
		*fdarray = tmp;
	}
	if (ft_strchr(*fdarray, '\n'))
	{
		len = strlnd(*fdarray, '\n');
		*line = ft_strsub(*fdarray, 0, len);
		tmp = ft_strsub(*fdarray, len + 1, ft_strlen(*fdarray + len + 1));
		ft_strdel(fdarray);
		*fdarray = tmp;
		if (*fdarray[0] == 0)
			ft_strdel(fdarray);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*fdarray[FD_SIZE];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || fd > FD_SIZE || (ret = read(fd, buf, 0) < 0))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (fdarray[fd] == NULL)
			fdarray[fd] = ft_strnew(1);
		if (ft_get_line(line, buf, &fdarray[fd]) == 1)
			return (1);
	}
	if (ret == 0 && fdarray[fd] == NULL)
		return (0);
	if (ft_get_line(line, NULL, &fdarray[fd]) == 1)
		return (1);
	else if (ret == 0 && fdarray[fd] != NULL)
		return (ft_last_line(line, &fdarray[fd]));
	return (ret);
}
