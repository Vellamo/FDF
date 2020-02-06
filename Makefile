# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 11:07:33 by lharvey           #+#    #+#              #
#    Updated: 2020/02/06 14:15:47 by lharvey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEDR = fdf.h

LIBFT = ./Libft

MINILIBX = ./minilibx_mms_20191025_beta

SRCS = main.c 

OBJECTS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	make -C $(MINILIBX)
	@gcc $(FLAGS) $(SRCS) $(LIBFT)/libft.a -o $(NAME)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
