#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>

char *create_hex(void)
{
	int p1 = 4;
	int randy = 0;
	char rgb[11];
	rgb[10]= 0;
	rgb[0] = '0';
	rgb[1] = 'x';
	rgb[2] = '0';
	rgb[3] = '0';
	char *string;
	while (p1 != 11)
	{
		if (randy)
			printf("randy = %i\n", randy);
		if ((randy = rand() % 10) % 2 == 0)
			rgb[p1] = (57 + rand() / (RAND_MAX / (48 - 57 + 1) + 1));
		else
			rgb[p1] = (70 + rand() / (RAND_MAX / (65 - 70 + 1) + 1));
		p1++;
	}
	string = ft_strdup(rgb);
	return (string);
}


int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*string;
	int		x, y;
	x = 0;
	y = 35;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 350, 200, "dude me too");
	string = create_hex();
	mlx_string_put(mlx_ptr, win_ptr, 1, 15, (int)string, string);
	ft_strdel(&string);
	string = create_hex();
	mlx_string_put(mlx_ptr, win_ptr, 1, 35, (int)string, string);
//	mlx_string_put(mlx_ptr, win_ptr, 1, 55, (int)string, string);
//	mlx_string_put(mlx_ptr, win_ptr, 1, 75, (int)string, string);
//	mlx_string_put(mlx_ptr, win_ptr, 1, 95, (int)string, string);
//	mlx_string_put(mlx_ptr, win_ptr, 1, 115, (int)string, string);
	mlx_loop(mlx_ptr);
}
