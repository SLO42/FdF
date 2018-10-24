# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/20 21:33:15 by saolivei          #+#    #+#              #
#    Updated: 2018/10/20 21:33:21 by saolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c 
SRCD = ./
INCL = ./incl/
OBJ = $(addprefix $(OBJD),$(SRCS:.c=.o))
OBJD = ./obs/

#libft library
FT_LINK = -L ./libft/ -l ft
FT = ./libft/
FT_INCL = -I ./libft/
FT_LIB = $(addprefix $(FT),libft.a)


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

obj:
	$(MK_O) $(OBJD)

$(OBJD)%.o:$(SRCD)%.c
	$(CC) $(CFLAGS) $(MLX_INCL) $(FT_INCL) -I $(INCL) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LINK) $(FT_LINK) -lm -o $(NAME)

clean:
	$(RM) $(OBJD)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean:	clean
	$(RM) $(NAME)
	make -C $(FT) fclean

re: fclean all