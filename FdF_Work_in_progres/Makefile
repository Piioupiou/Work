# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2013/12/22 20:47:02 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./fdf.c ./ft_tools.c

OBJ = ./fdf.o ./ft_tools.o

NAME = fdf

all: $(MAKE) $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L libft/ -lft -L/usr/X11/lib\
		-lmlx -lXext -lX11

$(MAKE) :
	make -C ./libft

clean :
	/bin/rm -f  $(OBJ)

fclean : make clean
	/bin/rm -f $(NAME)

re : make fclean all

.PHONY: all clean fclean re
