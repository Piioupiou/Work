# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2014/01/26 10:30:59 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./main.c

OBJ = ./main.o

NAME = filler

all: $(MAKE) $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L libft/ -lft

$(MAKE) :
	make -C ./libft

clean :
	/bin/rm -f  $(OBJ)

fclean : clean
	 make -C ./libft fclean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
