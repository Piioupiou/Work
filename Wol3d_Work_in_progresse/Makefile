# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2014/01/19 10:33:54 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/main.c \
	  ./src/ft_raycasting.c \
	  ./src/ft_colision.c \
	  ./src/ft_init.c \
	  ./src/ft_draw.c \
	  ./src/ft_tools.c

OBJ = ./main.o \
	  ./ft_raycasting.o \
	  ./ft_colision.o \
	  ./ft_init.o \
	  ./ft_draw.o \
	  ./ft_tools.o

NAME = Wolf3d

all: $(MAKE) $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -O3 -o $(NAME) $(SRC) -L libft/ -lft -L/usr/X11/lib\
		-lmlx -lXext -lX11 -I/opt/X11/include/X11

$(MAKE) :
	make -C ./libft

clean :
	/bin/rm -f  $(OBJ)

fclean : clean
	 make -C ./libft fclean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
