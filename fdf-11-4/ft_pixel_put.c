/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:01:01 by saolivei          #+#    #+#             */
/*   Updated: 2018/11/04 08:25:54 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char static	*check_clear(char *string)
{
	if (string)
		ft_strdel(&string);
	string = ft_create_hex();
	return (string);
}

void	ft_pixel_put(char *str, t_mlx *mlx, int height)
{
	size_t count;
    int i, z, y;
    char *color;
        
    color = NULL;
    i = 0;
    z = 0;
    y = 0;
	if (str[i] != ' ' && str[i] != 0)
    {
		count = 1;
        color = check_clear(color);
        y = 0;
        while (y < 10)
        (void)(mlx_pixel_put(mlx->mlx, mlx->win, (count * 10) + y++, height * 25, (int)strtol(color, NULL, 16)));
        y = 0;
        while (y < 25)
            (void)(mlx_pixel_put(mlx->mlx, mlx->win, (count * 10), (height * 25) + y++, (int)strtol(color, NULL, 16)));
    }
	else
		count = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ' && str[i] != 0)
				i++;
			if (str[i] != ' ' && str[i] != 0)
            {
				count++;
                color = check_clear(color);
               y = 0;
               while (y < 10)
                  (void)(mlx_pixel_put(mlx->mlx, mlx->win, (count * 10) + y++, height * 25, (int)strtol(color, NULL, 16)));
               y = 0;
               while (y < 25)
                   (void)(mlx_pixel_put(mlx->mlx, mlx->win, (count * 10), (height * 25) + y++, (int)strtol(color, NULL, 16)));
          }
		}
		else
			i++;
	}
	return ;
}

