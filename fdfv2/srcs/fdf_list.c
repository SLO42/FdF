/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:27:18 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 10:57:10 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define COLOR fdf->tmp_col

void			fix_list(t_fdf *fdf)
{
	t_pixel *tmp;

	tmp = *fdf->list;
	if (fdf->col->min == 0)
		return ;
	while ((tmp = tmp->next) != NULL)
		tmp->z += -(fdf->col->min);
}

void			add_point(t_pixel **list, t_pixel *new)
{
	t_pixel	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_pixel			*fdf_list_at(t_fdf *fdf, t_pixel *sy)
{
	t_pixel	*above;

	above = *fdf->list;
	while (above)
	{
		if (above->y != (sy->y - 1))
			above = above->next;
		else if (above->x != sy->x)
			above = above->next;
		else
			return (above);
	}
	return (NULL);
}

void			fdf_color_list(t_fdf *fdf)
{
	t_pixel *tmp;

	tmp = *fdf->list;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->z == fdf->col->max)
			tmp->color = fdf->col->c_max;
		else
			tmp->color = tmp->z == fdf->col->min ? fdf->col->c_min : COLOR;
		tmp = tmp->next;
	}
}

t_pixel			*create_point(t_fdf *fdf, int z, int x, int y)
{
	t_pixel	*elm;

	if (!(elm = (t_pixel*)ft_memalloc(sizeof(elm))))
		return (NULL);
	if (x == -1 && x == y && x == z)
		elm->end = 1;
	else if (x == fdf->img->xy.x - 1)
		elm->end = 1;
	else
		elm->end = 0;
	elm->z = z;
	elm->x = x;
	elm->y = y;
	elm->next = NULL;
	return (elm);
}
