# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2013/12/17 23:18:41 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./get_next_line.c ./fdf.c

OBJ = ./get_next_line.o ./fdf.o

NAME = fdf

all: $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -g

clean :
	/bin/rm -f  $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
