/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:24:48 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 10:57:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_y_move(t_fdf *fdf, int override)
{
	if (override == -6 && fdf->mody < 1000)
		fdf->mody += 10;
	else if (override == 6 && fdf->mody > -500)
		fdf->mody -= 10;
}

void	fdf_x_move(t_fdf *fdf, int override)
{
	if (override == -5 && fdf->modx < 500)
		fdf->modx += 10;
	else if (override == 5 && fdf->modx > -500)
		fdf->modx -= 10;
}

void	fdf_toggle_color(t_fdf *fdf)
{
	char	*tmp;

	fdf->tog = fdf->tog == 1 ? 0 : 0;
	tmp = ft_create_hex();
	fdf->color = ft_strjoin("00", tmp);
	fdf->col->c_max = ft_atoi_base(fdf->color, 16);
	free(tmp);
	free(fdf->color);
	tmp = ft_create_hex();
	fdf->color = ft_strjoin("00", tmp);
	fdf->tmp_col = ft_atoi_base(fdf->color, 16);
	free(tmp);
	free(fdf->color);
	fdf_color_list(fdf);
}
