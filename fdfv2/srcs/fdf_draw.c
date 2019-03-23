/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:01:01 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:16:05 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fdf_create_pixel
*/

void			fdf_create_pixel(t_cord *xy, t_fdf *f)
{
	if (xy->x < WIN_X && xy->x > 0 && xy->y < WIN_Y && xy->y > 0)
	{
		if (xy->x >= 0 && xy->x < WIN_X && xy->y >= 0 && xy->y < WIN_Y)
			f->img->dadd[(xy->x * f->img->bpp) /
				(8 * sizeof(*f->img->dadd)) +
				(xy->y * f->img->size_line) / sizeof(*f->img->dadd)] =
				mlx_get_color_value(f->mlx_p, fdf_color(f));
	}
}

/*
** fdf_p_line
*/

void			fdf_p_line(t_fdf *fdf, t_cord *start, t_cord *end)
{
	int		i;
	t_cord	xy;
	t_cord	tmp;
	int		max;

	i = -1;
	tmp.x = (start->x - end->x) > 0 ? start->x - end->x : -(start->x - end->x);
	tmp.y = (start->y - end->y) > 0 ? start->y - end->y : -(start->y - end->y);
	max = tmp.x < tmp.y ? tmp.y : tmp.x;
	while (i++ < max)
	{
		xy.x = start->x + (i * (end->x - start->x) / (max + 1));
		xy.y = start->y + (i * (end->y - start->y) / (max + 1));
		fdf_create_pixel(&xy, &*fdf);
	}
}

/*
** generate_perspective_math
*/

t_cord			generate_perspective_math(t_fdf *fdf, t_pixel *list)
{
	t_cord		real;
	double		x;
	double		y;
	double		z;

	fdf->frac->x = (double)(fdf->zoom * WIN_X) / (double)(100 * fdf->img->xy.x);
	fdf->frac->y = (double)(fdf->zoom * WIN_Y) / (double)(100 * fdf->img->xy.y);
	x = fdf->frac->x + (list->x * fdf->frac->x * (double)fdf->s.x);
	y = fdf->frac->y + (list->y * fdf->frac->y * (double)fdf->s.y);
	z = (list->z * fdf->frac->y) / 120.0f + (50.0f * cos(x) * fdf->w.x) +
		(50.0f * cos(y) * fdf->w.y) + (list->z * fdf->w.z);
	real.x = (WIN_Y * 2 / 5) +
		(x * cos(M_PI / 6.0f)) +
		(y * cos((M_PI / 6.0f) + 2.0f * (M_PI / 3.0f))) +
		(z * (z * cos((M_PI / 6.0f) - (2.0f * (M_PI / 3.0f))))) + fdf->modx;
	real.y = (WIN_X / 10) +
		(x * sin(M_PI / 6.0f)) +
		(y * sin((M_PI / 6.0f) + 2.0f * (M_PI / 3.0f))) +
		(z * (z * sin((M_PI / 6.0f) - (2.0f * (M_PI / 3.0f)))) +
		(5.0f * (cos((z / M_PI))))) + fdf->mody;
	return (real);
}

/*
** drawlien
*/

void			fdf_drawline(t_fdf *fdf, t_pixel *s)
{
	t_cord	start;
	t_cord	end;
	t_pixel *tmp;

	if (s->x == -5 && s->x == s->z && s->z == s->end)
		s = s->next;
	while (s->x != -1)
	{
		start = generate_perspective_math(&*fdf, s);
		fdf->tmp_col = s->color;
		if (s->x < fdf->img->xy.x - 1)
		{
			tmp = s->next;
			end = generate_perspective_math(&*fdf, tmp);
			fdf_p_line(&*fdf, &start, &end);
		}
		if (s->y > 0)
		{
			tmp = fdf_list_at(fdf, s);
			end = generate_perspective_math(&*fdf, tmp);
			fdf_p_line(&*fdf, &start, &end);
		}
		s = s->next;
	}
}
