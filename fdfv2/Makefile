# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/20 21:33:15 by saolivei          #+#    #+#              #
#    Updated: 2019/03/23 10:57:15 by saolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c fdf_keys.c fdf_draw.c fdf_zoom_stretch.c fdf_move.c map.c \
			uselessmath.c fdf_init.c fdf_list.c\

SRCD = ./srcs/
INCL = ./incl/
OBJ = $(addprefix $(OBJD),$(SRCS:.c=.o))
OBJD = ./obs/

#libft library
FT_LINK = -L ./ft_printf/ -l ftprintf
FT = ./ft_printf/
FT_INCL = -I ./ft_printf/
FT_LIB = $(addprefix $(FT),libftprintf.a)


#Compiler
CC = gcc
DB = -g
CFLAGS = -Wall -Werror -Wextra -g
FLAG = -Wall -Werror -Wextra
AR = ar rc
RL = ranlib
RM = /bin/rm -rf
MK_O = mkdir -p

# mlx library
MLX = ./minilibx/
MLX_LIB = -L $(addprefix $(mlx),mlx.a)
MLX_INCL = -I ./minilibx/
MLX_LINK = -L ./minilibx -l mlx $(FW)
FW = -framework OpenGL -framework AppKit

# cc main.c -L minilibx/ -lmlx -framework OpenGL -framework AppKit -L libft/ -lft -o "whatever"
.PHONY: obj clean fclean re

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

$(OBJD)%.o:$(SRCD)%.c
	$(CC) $(CFLAGS) $(MLX_INCL) $(FT_INCL) -I $(INCL) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	@ make -C $(MLX)

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(MLX_LINK) $(FT_LINK) -lm  -I $(INCL) -o $(NAME)

clean:
	@ /bin/rm -rf $(OBJ)
	make -C $(FT) fclean
	make -C $(MLX) clean

fclean:	clean
	$(RM) $(NAME)
	make -C $(FT) fclean

re: fclean all