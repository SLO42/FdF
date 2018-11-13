/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:54:20 by saolivei          #+#    #+#             */
/*   Updated: 2018/11/06 12:25:26 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// hit escape to leave the program
int	key_pressed(int key, t_mlx *mlx)
{
    (void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
    return (0);
}
