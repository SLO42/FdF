#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include <fcntl.h>

char static	*check_clear(char *string)
{
	if (string)
		ft_strdel(&string);
	string = ft_create_hex();
	return (string);
}

// hit escape to leave the program
int	escape_key(int key)
{
	if (key == ESC)
		exit(SUCCESS);
	return(0);
}


int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*string;
	int		x, y;

	string = NULL;
	x = 0;
	y = 35;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 100, 125, "get good");
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 15, (int)strtol(string, NULL, 16), string);
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 35, (int)strtol(string, NULL, 16), string);
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 55, (int)strtol(string, NULL, 16), string);
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 75, (int)strtol(string, NULL, 16), string);
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 95, (int)strtol(string, NULL, 16), string);
	mlx_key_hook(win_ptr, escape_key, mlx_ptr);
	mlx_loop(mlx_ptr);
}
