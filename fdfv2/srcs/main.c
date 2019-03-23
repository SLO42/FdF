/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:37:49 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:23:08 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		fdf_pixel_free(t_pixel **list)
{
	t_pixel *temp;
	t_pixel *new;

	new = *list;
	while (new)
	{
		temp = new;
		free(new);
		new = temp->next;
	}
	*list = NULL;
	return (0);
}

static	void	fdf_exit_help(t_fdf *fdf)
{
	if (fdf->mlx_p)
	{
		fdf->win_p ? mlx_destroy_window(fdf->mlx_p, fdf->win_p) : 0;
		if (fdf->img_p)
		{
			mlx_destroy_image(fdf->mlx_p, fdf->img_p);
			if (fdf->img)
				free(fdf->img);
		}
		free(fdf->mlx_p);
	}
}

int				fdf_exit(t_fdf *fdf)
{
	fdf_exit_help(fdf);
	fdf->col ? free(fdf->col) : 0;
	fdf->frac ? free(fdf->frac) : 0;
	fdf->map ? free(fdf->map) : 0;
	fdf->list ? fdf_pixel_free(fdf->list) : 0;
	ft_printf("clean exit");
	exit(EXIT_SUCCESS);
	return (1);
}

int				main(int arg_count, char const **argv)
{
	t_fdf			*fdf;

	if (ft_printf("counting arguments... %d\n", arg_count) && arg_count != 2)
		exit(ft_printf(FDF_ERROR_ARGC));
	if (!(fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (ft_printf(FDF_ERROR_MEM));
	fdf->mlx_p = mlx_init();
	create_static_win_img(&*fdf, argv[1]);
	fdf_color_list(&*fdf);
	fdf_drawline(&*fdf, &*fdf->start);
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, 0, 0);
	fdf_display_help(fdf);
	mlx_expose_hook(fdf->win_p, &exposed_hook, &*fdf);
	mlx_key_hook(fdf->win_p, &key_pressed, &*fdf);
	mlx_hook(fdf->win_p, 17, 1L << 17, &close, NULL);
	mlx_loop(fdf->mlx_p);
}
