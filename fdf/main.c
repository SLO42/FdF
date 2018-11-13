/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:37:49 by saolivei          #+#    #+#             */
/*   Updated: 2018/11/04 13:16:14 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	if ((!(mlx->mlx = mlx_init())) 
		|| (!(mlx->win = mlx_new_window(mlx->mlx, WIN_X, WIN_Y, "title")))
		|| (!(mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y))))
	{
		perror("was unable to init");
		exit(EXIT_FAILURE);
	}
	if (!(mlx->map = (char***)ft_memalloc(3)))
	{
		perror("failed to do ***map");
		exit(EXIT_FAILURE);	
	}
	mlx_key_hook(mlx->win, key_pressed, mlx);
	mlx->fd = open(argv[1], O_RDONLY);
	fdf = NULL;
	while (get_next_line(mlx->fd, &fdf) > 0)
	{
		width = ft_wordcountd(fdf, ' ');
		ft_pixel_put(fdf, mlx, height, width);
		ft_strdel(mlx->map[height]);
		height++;
	}
	close(mlx->fd);
	printf("height is %i\n", height);
	mlx_loop(mlx->mlx);
}
