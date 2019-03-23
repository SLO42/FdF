# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 18:52:46 by saolivei          #+#    #+#              #
#    Updated: 2019/02/25 15:48:51 by saolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_ftoa.c ft_helpers.c ft_helpers2.c ft_parsef.c \
			ft_printf.c ft_spec_pointer.c ft_spec_signed_int.c \
			ft_spec_unsigned_int_h.c ft_spec_unsigned_int_hh.c \
			ft_spec_unsigned_int_l.c ft_spec_unsigned_int_ll.c \
			ft_spec_unsigned_int_uint.c ft_spec.c spec_float.c \
			spec_signed_unsigned.c ft_exit.c ft_lltoa.c ft_ftoa.c \
			ft_chr_in_str.c ft_clean_parse.c ft_helpers3.c \

SRCD = ./src/
INCL = ./incl/
OBJ = $(addprefix $(OBJD),$(SRC:.c=.o))
OBJD = ./obs/

#libft library
FT_LINK = -L ./libft/ -l ft
FT = ./libft/
FT_INCL = -I ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_LIB_OB = $(addprefix $(FT),*.o)

#Compiler
CC = gcc
DB = -g
CFLAGS = -Wall -Werror -Wextra
FLAGS = -Wall -Werror -Wextra
AR = ar rc
RL = ranlib
RM = /bin/rm -rf
MK_O = mkdir -p

.PHONY:
	clean fclean re

all: $(FT_LIB) $(NAME)


$(OBJD)%.o:$(SRCD)%.c
	@ $(CC) $(CFLAGS) $(FT_INCL) -I $(INCL) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	@ $(AR) $(NAME) $(OBJ) $(FT_LIB_OB)
	@ $(RL) $(NAME)

clean:
	@ $(RM) $(OBJ)
	@make -C $(FT) clean

fclean: clean
	@ $(RM) $(NAME)
	@make -C $(FT) fclean

re: fclean all
