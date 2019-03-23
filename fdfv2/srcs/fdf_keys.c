/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:54:20 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:21:57 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ZOOM_IN "| Press the keyboard key '+/=' to zoom in  |"
#define ZOOM_OUT "| Press the Keyboard key '-/_' to zoom out |"
#define Y_UP "| Press the UP ARROW to increment y points |"
#define Y_DN "|Press the DOWN ARROW to decrement y points|"
#define X_UP "|Press the RIGHT ARROW to increment x points|"
#define X_DN "|Press the LEFT ARROW to decrement x points |"
#define Z_UP "|Press the keybaord key '7/&' to increment z|"
#define Z_DN "|Press the keybaord key '6/^' to decrement z|"
#define C_SP "|Press SPACE to Change the colors. Will start if no color|"
#define STATS fdf->mlx_p, fdf->win_p, 120, 1460, 0xffffff, C_SP
#define HOW_TO_ZOOM_IN fdf->mlx_p, fdf->win_p, 10, 1400, 0xffffff, ZOOM_IN
#define HOW_TO_ZOOM_OUT fdf->mlx_p, fdf->win_p, 10, 1415, 0xffffff, ZOOM_OUT
#define HOW_TO_STRETCH_Y_UP fdf->mlx_p, fdf->win_p, 10, 1430, 0xffffff, Y_UP
#define HOW_TO_STRETCH_Y_DN fdf->mlx_p, fdf->win_p, 10, 1445, 0xffffff, Y_DN
#define HOW_TO_STRETCH_X_UP fdf->mlx_p, fdf->win_p, 440, 1430, 0xffffff, X_UP
#define HOW_TO_STRETCH_X_DN fdf->mlx_p, fdf->win_p, 440, 1445, 0xffffff, X_DN
#define HOW_TO_SCALE_Z_UP fdf->mlx_p, fdf->win_p, 440, 1400, 0xffffff, Z_UP
#define HOW_TO_SCALE_Z_DOWN fdf->mlx_p, fdf->win_p, 440, 1415, 0xffffff, Z_DN
#define HOW_TO_START_CHANGE_COLOR STATS

/*
** hit escape to leave the program
** 10,52,54 = unused; 36 = return ; 48 = tab; 49 = space ; 51 = Delete
** 53 = ESC; 55 = command
*/

void			fdf_display_help(t_fdf *fdf)
{
	mlx_string_put(HOW_TO_ZOOM_IN);
	mlx_string_put(HOW_TO_ZOOM_OUT);
	mlx_string_put(HOW_TO_STRETCH_Y_UP);
	mlx_string_put(HOW_TO_STRETCH_Y_DN);
	mlx_string_put(HOW_TO_STRETCH_X_UP);
	mlx_string_put(HOW_TO_STRETCH_X_DN);
	mlx_string_put(HOW_TO_SCALE_Z_UP);
	mlx_string_put(HOW_TO_SCALE_Z_DOWN);
	mlx_string_put(HOW_TO_START_CHANGE_COLOR);
}

static	void	key_helper1(char *action, t_fdf *fdf, int override)
{
	ft_bzero(fdf->img->dadd, WIN_X * WIN_Y * fdf->img->bpp / 8);
	if (override == 1 || override == -1)
		fdf_zoom(fdf, override);
	else if (override == 2 || override == -2)
		fdf_y_stretch(fdf, override);
	else if (override == 3 || override == -3)
		fdf_x_stretch(fdf, override);
	else if (override == 4 || override == -4)
		fdf_z_stretch(fdf, override);
	else if (override == 5 || override == -5)
		fdf_x_move(fdf, override);
	else if (override == 6 || override == -6)
		fdf_y_move(fdf, override);
	else if (override == 10)
		fdf_toggle_color(fdf);
	fdf_drawline(fdf, fdf->start);
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, 0, 0);
	fdf_display_help(fdf);
	ft_putendl(action);
}

static	int		key_pressed2(t_fdf *fdf)
{
	if (fdf->fd == 86)
		key_helper1("move image left", fdf, 5);
	else if (fdf->fd == 88)
		key_helper1("move image right", fdf, -5);
	else if (fdf->fd == 91)
		key_helper1("move image up", fdf, 6);
	else if (fdf->fd == 84)
		key_helper1("move image down", fdf, -6);
	else if (fdf->fd == 49)
		key_helper1("Toggle Random Colors", fdf, 10);
	return (0);
}

int				key_pressed(int key, t_fdf *fdf)
{
	fdf->fd = key;
	if (fdf->fd == 53)
		fdf_exit(fdf);
	else if (fdf->fd == 24)
		key_helper1("zoom in", fdf, 1);
	else if (fdf->fd == 27)
		key_helper1("zoom out", fdf, -1);
	else if (fdf->fd == 126)
		key_helper1("stretch Y +", fdf, 2);
	else if (fdf->fd == 125)
		key_helper1("stretch Y -", fdf, -2);
	else if (fdf->fd == 124)
		key_helper1("stretch x +", fdf, 3);
	else if (fdf->fd == 123)
		key_helper1("stretch x -", fdf, -3);
	else if (fdf->fd == 26)
		key_helper1("stretch z +", fdf, 4);
	else if (fdf->fd == 22)
		key_helper1("stretch z -", fdf, -4);
	else
		return (key_pressed2(fdf));
	return (0);
}

int				exposed_hook(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img_p, 0, 0);
	fdf_display_help(fdf);
	return (0);
}
