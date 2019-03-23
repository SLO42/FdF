/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom_stretch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:22:06 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/22 20:33:26 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_zoom(t_fdf *fdf, int override)
{
	if (override == -1 && fdf->zoom > 2)
		fdf->zoom -= 0.05;
	else if (override == 1 && fdf->zoom < 5)
		fdf->zoom += 0.05;
}

void	fdf_y_stretch(t_fdf *fdf, int override)
{
	if (override == 2 && fdf->s.y < 10)
		fdf->s.y += 1;
	else if (override == -2 && fdf->s.y > 5)
		fdf->s.y -= 1;
}

void	fdf_x_stretch(t_fdf *fdf, int override)
{
	if (override == 3 && fdf->s.x < 10)
		fdf->s.x += 1;
	else if (override == -3 && fdf->s.x > 5)
		fdf->s.x -= 1;
}

void	fdf_z_stretch(t_fdf *fdf, int override)
{
	if (override == 4 && fdf->w.z < 0.3 && fdf->col->max > 19)
		fdf->w.z += 0.05;
	else if (override == 4 && fdf->w.z < 1 && fdf->col->max < 20)
		fdf->w.z += 0.05;
	else if (override == -4 && fdf->w.z > 0.00)
		fdf->w.z -= 0.05;
}
