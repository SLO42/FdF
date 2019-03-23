/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:25:39 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:24:35 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define TITLE (char*)file

void	create_static_win_img(t_fdf *fdf, char const *file)
{
	static	int	windowx = WIN_X;
	static	int	windowy = WIN_Y;

	ft_printf("creating static image with size X:%d|Y:%d\n", WIN_X, WIN_Y);
	if (!(fdf->mlx_p)
		|| !(fdf->win_p = mlx_new_window(fdf->mlx_p, windowx, windowy, TITLE))
		|| !(fdf->img_p = mlx_new_image(fdf->mlx_p, windowx, windowy))
		|| !(fdf->img = img_init(fdf, file))
		|| !(fdf->col = get_z_max_min(fdf))
		|| !(fdf->frac = (t_fract*)ft_memalloc(sizeof(t_fract))))
		ft_printf(FDF_ERROR_MEM) ? fdf_exit(fdf) : (void)fdf;
	fix_list(&*fdf);
	fdf->s.x = 10;
	fdf->s.y = 10;
	fdf->w.x = 0.0;
	fdf->w.y = 0.0;
	fdf->w.z = 0.1;
	fdf->tog = 1;
	fdf->modx = 0;
	fdf->mody = 100;
}

t_pixel	**point_init(void)
{
	t_pixel	**list;
	t_pixel	*start;

	ft_printf("creating points\n");
	if (!(list = (t_pixel**)ft_memalloc(sizeof(t_pixel*)))
		|| !(start = (t_pixel*)ft_memalloc(sizeof(t_pixel))))
		return (NULL);
	start->next = NULL;
	start->x = -5;
	start->y = -5;
	start->z = -5;
	start->end = -5;
	*list = start;
	return (list);
}

t_image	*img_init(t_fdf *fdf, char const *file)
{
	t_image	*img;

	ft_printf("creating img struct\n");
	if (!(img = (t_image*)ft_memalloc(sizeof(t_image))))
		return (NULL);
	img->bpp = 8;
	img->end = 1;
	img->xy = get_width(file, fdf);
	img->dadd = malloc(sizeof(*img->dadd) * WIN_X * WIN_Y);
	if (!(img->dadd = mlx_get_data_addr(fdf->img_p, &img->bpp,
			&img->size_line, &img->end)))
	{
		free(img);
		return (NULL);
	}
	fdf->zoom = 3;
	return (img);
}
