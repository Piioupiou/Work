# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2014/02/23 20:17:45 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./main.c \
	  ./ft_ants.c \
	  ./ft_pathfinding.c \
	  ./ft_parse.c

OBJ = ./main.o \
	  ./ft_ants.o \
	  ./ft_pathfinding.o \
	  ./ft_parse.o

NAME = lem-in

all: $(MAKE) $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L libft/ -lft -g

$(MAKE) :
	make -C ./libft

clean :
	/bin/rm -f  $(OBJ)

fclean : clean
	 make -C ./libft fclean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
