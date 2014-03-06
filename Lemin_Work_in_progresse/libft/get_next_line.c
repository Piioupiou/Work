/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 02:43:19 by pgallois          #+#    #+#             */
/*   Updated: 2014/03/04 21:46:39 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		looking_for_end_of_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*mem = "";
	int				ret;
	char			*buffer;

	if (BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (!(looking_for_end_of_line(mem)) && (ret == BUFF_SIZE))
	{
		buffer = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		mem = ft_strjoin(mem, buffer);
		free(buffer);
	}
	looking_for_end_of_line(mem);
	*line = ft_strdup(mem);
	mem = mem + ft_strlen(*line) + 1;
	if (ret < BUFF_SIZE && (ft_strlen(*line) == 0) && ft_strlen(mem) == 0)
		return (0);
	return (1);
}
