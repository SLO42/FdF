/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:13:29 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:09:14 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define INVALID_FORMAT "File format is wrong in %s \n'%s'\n on line %d"
#define FT_ISDIGIT_OR_ASCII(a) (ft_isdigit(a) || ft_isascii(a))

t_mnm			*get_z_max_min(t_fdf *fdf)
{
	int		i;
	int		j;
	t_mnm	*m_m;

	if (!(m_m = (t_mnm*)ft_memalloc(sizeof(t_mnm))))
		return (NULL);
	i = 0;
	m_m->max = 1;
	m_m->min = 0;
	fdf->list = point_init();
	fdf->start = *fdf->list;
	while (i < fdf->img->xy.y)
	{
		j = 0;
		while (j < fdf->img->xy.x)
		{
			m_m->max = fdf->map[i][j] > m_m->max ? fdf->map[i][j] : m_m->max;
			m_m->min = fdf->map[i][j] < m_m->min ? fdf->map[i][j] : m_m->min;
			add_point(&*fdf->list, create_point(fdf, fdf->map[i][j], j, i));
			j++;
		}
		i++;
	}
	add_point(&*fdf->list, create_point(fdf, -1, -1, -1));
	return (m_m);
}

static	void	create_map_helper(t_fdf *fdf, int i, t_cord xy)
{
	if (!(fdf->map[i] = ft_strnew(xy.x)))
	{
		free(fdf->map);
		fdf_exit(fdf);
	}
}

void			create_map(t_fdf *fdf, char const *file, t_cord xy)
{
	int			fd;
	char		*line;
	int			len;
	int			i;

	fd = open(file, O_RDONLY);
	if (!(fdf->map = (char **)malloc(sizeof(*fdf->map) * xy.y)))
		fdf_exit(fdf);
	i = -1;
	while (get_next_line(fd, &line) && i++ < 9999)
	{
		len = 0;
		create_map_helper(&*fdf, i, xy);
		while (len < xy.x)
		{
			fdf->map[i][len] = ft_atoi(line);
			while ((FT_ISDIGIT_OR_ASCII(*line)) && !ft_isspace(*line))
				line++;
			while (ft_isspace(*line))
				line++;
			len++;
		}
	}
	close(fd);
}

t_cord			get_stats(t_cord w, char const *fi, char *l, t_fdf *f)
{
	f->fd = open(fi, O_RDONLY);
	if (get_next_line(f->fd, &l))
	{
		w.y++;
		w.x = ft_wordcountd(l, ' ');
		free(l);
		return (w);
	}
	else
		ft_printf("Could not read file") ? exit(close(f->fd) + fdf_exit(f)) : 0;
	return (w);
}

t_cord			get_width(char const *file, t_fdf *fdf)
{
	char			*line;
	t_cord			widhei;

	widhei.x = 0;
	widhei.y = 0;
	if (ft_strstr(file, ".fdf\0") == file)
		ft_printf(FDF_ERROR_ARGC) ? fdf_exit(fdf) : 0;
	line = NULL;
	widhei = get_stats(widhei, file, line, fdf);
	while (get_next_line(fdf->fd, &line))
	{
		widhei.y++;
		if (widhei.x != (int)ft_wordcountd(line, ' '))
		{
			ft_printf(INVALID_FORMAT, file, line, widhei.y);
			free(line);
			close(fdf->fd);
			fdf_exit(fdf);
		}
		free(line);
	}
	close(fdf->fd);
	create_map(fdf, file, widhei);
	return (widhei);
}
