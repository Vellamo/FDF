# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 11:07:33 by lharvey           #+#    #+#              #
#    Updated: 2020/02/20 15:08:34 by lharvey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

PREFIX = /usr/local

LIBFT = ./libft
MLXINC = $(PREFIX)/include/mlx.h
MLXLIB = $(PREFIX)/lib/ -lmlx -framework OpenGL -framework AppKit

SRCS = main.c check_wireframe.c convert_wireframe.c draw_wireframe.c
OBJECTS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLAGS) -I $(MLXINC) -L $(MLXLIB) $(SRCS) $(LIBFT)/libft.a -o $(NAME)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
