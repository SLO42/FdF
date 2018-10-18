# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 11:04:11 by saolivei          #+#    #+#              #
#    Updated: 2018/10/16 10:39:16 by saolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_intlen.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c \
			ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c ft_lstmap.c \
			ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
			ft_putstr.c ft_putstr_fd.c ft_isspace.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
			ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
			ft_toupper.c ft_wordcountd.c ft_putchar_fd.c get_next_line.c\

OP = $(SRCS:.c=.o)

.PHONY:
	clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OP)
	@ranlib $(NAME)
	@echo "Successful Make" [ $(NAME) ] "\033[4mWOoHOO\033[0m"

clean: 
	@/bin/rm -f $(OP)
	@echo "\033[1;37m"CLEANED"\033[00m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;31m"CLEANER"\033[00m"

re: fclean all

