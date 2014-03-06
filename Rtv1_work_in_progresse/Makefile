# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2014/02/16 07:47:39 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/main.c \
	  ./src/point_operation.c \
	  ./src/ft_init.c \
	  ./src/ft_tools.c

OBJ = ./main.o \
	  ./src/point_operation.o \
	  ./src/ft_init.o \
	  ./src/ft_tools.o

NAME = RTv1

all: $(MAKE) $(NAME)

$(NAME) :
	cc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L libft/ -lft -L/usr/X11/lib\
		-lmlx -lXext -lX11 -I/opt/X11/include/X11 -g

$(MAKE) :
	make -C ./libft

clean :
	/bin/rm -f  $(OBJ)

fclean : clean
	 make -C ./libft fclean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
