/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 02:48:27 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/07 23:27:39 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <fcntl.h>
#define BUFF_SIZE 42

typedef struct 		s2_list
{
	char			*str;
	int				fd;
	struct s2_list	*next;
	struct s2_list	*prev;
}					t2_list;

int	ft_replace_chartonull(char *s, int c);
int	get_next_line(int const fd, char **line);

#endif /* !GET_NEXT_LINE_H */
