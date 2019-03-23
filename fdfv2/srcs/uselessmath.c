/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uselessmath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:12:57 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:25:02 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	if (current == 0)
		current = 1;
	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				fdf_color(t_fdf *fdf)
{
	return ((fdf->tog == 1) ? 0xFFFFFFF : fdf->tmp_col);
}
