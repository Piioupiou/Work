# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:00:48 by pgallois          #+#    #+#              #
#    Updated: 2013/12/31 05:37:23 by pgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./ft_pipex.c ./ft_pipex_error.c

OBJ = ./ft_pipex.o ./ft_pipex_error.o

NAME = pipex

all: $(MAKE) $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -L libft/ -lft

$(MAKE) :
	make -C ./libft

clean :
	/bin/rm -f  $(OBJ)

fclean : make clean
	/bin/rm -f $(NAME)

re : make fclean all

.PHONY: all clean fclean re
