/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:37:49 by saolivei          #+#    #+#             */
/*   Updated: 2018/11/04 08:23:37 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char const **argv)
{
	t_mlx 	*mlx;
	char	*fdf;
	int		width, height, i;

	if (ac != 2)
	{
		perror("please use syntax: './fdf example.fdf' : Thank you ");
		exit(EXIT_FAILURE);
	}
	height = 0;
	width = 0;
	i = 0;
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
	{
		perror("was unable to create struct");
		exit(EXIT_FAILURE);
	}
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, "title");
	mlx_key_hook(mlx->win, key_pressed, mlx);
	mlx->fd = open(argv[1], O_RDONLY);
	fdf = NULL;
	while (get_next_line(mlx->fd, &fdf) > 0)
	{
		ft_pixel_put(fdf, mlx, height);
		height++;
	}
	close(mlx->fd);
	printf("height is %i\n", height);
	mlx_loop(mlx->mlx);
}
