#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>
# include <limits.h>
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define SUCCESS 1
# define FAIL 0
# define ERROR -1

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
}           t_mlx;
#endif