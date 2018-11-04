#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <limits.h>
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define WIN_X 1500
# define WIN_Y 1900

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    **map;
    int     fd;
}           t_mlx;

int         key_pressed(int key, t_mlx *mlx);
void	    ft_pixel_put(char *str, t_mlx *mlx, int height);
#endif