/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:26:06 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/23 11:25:13 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../ft_printf/src/ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define WIN_X 1500
# define WIN_Y 1900
# define CONST(x) (const int)x
# define FDF_ERROR_ARGC "please use 1 argument | Format: 'NAME.fdf' |\n"
# define FDF_ERROR_MEM "NOT ENOUGH MEM, plz fix: plz'n'thx\n"
# define X_MASK 0

typedef	struct		s_mnm
{
	long			max;
	long			min;
	long			c_max;
	long			c_min;
}					t_mnm;

typedef	struct		s_pixel
{
	long			x;
	long			y;
	long			z;
	int				color;
	short			end;
	struct s_pixel	*next;
}					t_pixel;

typedef	struct		s_cord
{
	int				x;
	int				y;
}					t_cord;

typedef	struct		s_fract
{
	double			x;
	double			y;
}					t_fract;

typedef	struct	s_image
{
	char		*dadd;
	int			bpp;
	int			end;
	int			size_line;
	t_cord		xy;
}				t_image;

typedef	struct	s_fdf
{
	int			fd;
	void		*mlx_p;
	void		*win_p;
	void		*img_p;
	int			tmp_col;
	char		*color;
	int			tog;
	int			posx;
	int			posy;
	int			mody;
	int			modx;
	double		zoom;
	char		**map;
	t_cord		s;
	t_set		w;
	t_pixel		*start;
	t_image		*img;
	t_pixel		**list;
	t_mnm		*col;
	t_fract		*frac;
}				t_fdf;

void			create_static_win_img(t_fdf *fdf, char const *file);
t_mnm			*get_z_max_min(t_fdf *fdf);
t_image			*img_init(t_fdf *fdf, char const *file);
t_pixel			**point_init(void);
t_pixel			*fdf_list_at(t_fdf *fdf, t_pixel *sy);
t_pixel			*create_point(t_fdf *fdf, int z, int x, int y);
t_pixel			*get_above(t_fdf *fdf, int x, int y);
t_cord			get_width(char const *file, t_fdf *fdf);
t_cord			generate_perspective_math(t_fdf *fdf, t_pixel *list);
double			percent(int start, int end, int current);
int				get_light(int start, int end, double percentage);
int				fdf_color(t_fdf *fdf);
int				fdf_cal_grad(double per, t_mnm *m_m, t_pixel *s, t_fdf *fdf);
void			fix_list(t_fdf *fdf);
void			fdf_color_list(t_fdf *fdf);
void			ft_pixel_put(char *str, t_fdf *fdf, int height, int width);
void			fdf_create_pixel(t_cord *xy, t_fdf *f);
void			fdf_p_line(t_fdf *fdf, t_cord *start, t_cord *end);
void			fdf_drawline(t_fdf *fdf, t_pixel *s);
void			add_point(t_pixel **list, t_pixel *new);
void			create_map(t_fdf *fdf, char const *file, t_cord xy);

int				key_pressed(int key, t_fdf *fdf);
int				exposed_hook(t_fdf *fdf);
void			fdf_display_help(t_fdf *fdf);
void			fdf_zoom(t_fdf *fdf, int override);
void			fdf_y_stretch(t_fdf *fdf, int override);
void			fdf_x_stretch(t_fdf *fdf, int override);
void			fdf_z_stretch(t_fdf *fdf, int override);
void			fdf_y_move(t_fdf *fdf, int override);
void			fdf_x_move(t_fdf *fdf, int override);
void			fdf_toggle_color(t_fdf *fdf);

int				fdf_exit(t_fdf *fdf);

#endif