#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>

char *create_hex(void)
{
	int p1 = 0;
	int randy = 0;
	char rgb[11];
	rgb[6]= 0;
	char *string;
	while (p1 != 6)
	{
		if ((randy = rand() % 16) % 2 == 0)
			rgb[p1] = (57 + rand() / (RAND_MAX / (48 - 57 + 1) + 1));
		else
			rgb[p1] = (70 + rand() / (RAND_MAX / (65 - 70 + 1) + 1));
		if (randy)
		p1++;
	}
	string = ft_strdup(rgb);
	return (string);
}

char	*check_clear(char *string)
{
	if (string)
		ft_strdel(&string);
	string = create_hex();
	return (string);
}

int	escape_key(int key)
{
	if (key == 53)
		exit(1);
	return(0);
}


int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*string;
	int		x, y;
	srand(getpid());
	x = 0;
	y = 35;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 350, 200, "dude me too");
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 15, (int)strtol(string, NULL, 16), "~!@#$\%^&*()_");
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 35, (int)strtol(string, NULL, 16), "StayAway");
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 55, (int)strtol(string, NULL, 16), "i actually really like doing this");
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 75, (int)strtol(string, NULL, 16), "STUMPY");
	string = check_clear(string);
	mlx_string_put(mlx_ptr, win_ptr, 1, 95, (int)strtol(string, NULL, 16), "\'idk\'");
	mlx_key_hook(win_ptr, escape_key, mlx_ptr);
	mlx_loop(mlx_ptr);;;
}
