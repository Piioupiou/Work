/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 04:03:58 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/07 23:40:58 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_replace_chartonull(char *s, int c)
{
	int     i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			s[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str = "";
	char		*buf;
	int			a;

	*line = ft_strdup("\n");
	a = BUFF_SIZE;
	while (ft_replace_chartonull(str, '\n') != 1 && a == BUFF_SIZE)
	{
		buf = (char *) malloc(sizeof(char) * (BUFF_SIZE) + 1);
		if (buf == NULL)
			return (-1);
		a = read(fd, buf, BUFF_SIZE);
		buf[a] = '\0';
		str = ft_strjoin((char const *)str, buf);
		free(buf);
	}
	*line = ft_strdup(str);
	ft_replace_chartonull(*line, '\n');
	str = str + ft_strlen(*line) + 1;
	if (a != BUFF_SIZE && **line == 0 && *str == 0)
		return (0);
	return (1);
}

int	main()
{
	int fd;
	int fd2;
	int	fd3;
	char *line;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt",O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	return (0);
}
