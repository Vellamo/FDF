# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/15 11:07:33 by lharvey           #+#    #+#              #
#    Updated: 2020/01/15 11:08:29 by lharvey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEDR = fdf.h

LIBFT = ./Libft

SRCS = main.c 

OBJECTS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME):
	make -C $(LIBFT) fclean
	make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) $(LIBFT)/libft.a -o $(NAME)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
