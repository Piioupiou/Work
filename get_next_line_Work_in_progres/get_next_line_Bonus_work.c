/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 04:03:58 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/07 23:25:04 by pgallois         ###   ########.fr       */
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

t2_list	*ft_checkfd(t2_list *list, int const fd)
{
	t2_list	*tmp2;

	if (list == NULL)
	{
		list = (void *) malloc(sizeof(t2_list));
		list->prev = NULL;
	}
	tmp2 = (void *) malloc(sizeof(t2_list));
	while (list->prev != NULL)
		list = list->prev;
	if (list->fd == fd)
		return (list);
	while (list->next != NULL)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	tmp2 = (void *) malloc(sizeof(t2_list));
	tmp2->prev = list;
	list->next = tmp2;
	tmp2->fd = fd;
	tmp2->str = "";
	list = list->next;
	return (list);
}

int		get_next_line(int const fd, char **line)
{
	static t2_list	*list;
	char			*buf;
	int				a;

	list = ft_checkfd(list, fd);
	*line = ft_strdup("");
	a = BUFF_SIZE;
	while (ft_replace_chartonull((char *)list->str, '\n') != 1 && a == BUFF_SIZE)
	{
		buf = (char *) malloc(sizeof(char) * (BUFF_SIZE) + 1);
		if (buf == NULL)
			return (-1);
		a = read(fd, buf, BUFF_SIZE);
		buf[a + 1] = '\0';
		list->str = ft_strjoin((char const *)list->str, buf);
		free(buf);
	}
	*line = ft_strdup((char const *)list->str);
	ft_replace_chartonull(*line, '\n');
	list->str = list->str + ft_strlen((char *) list->str) + 1;
	if (a != BUFF_SIZE && **line == 0 && *(char *)list->str == 0)
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
/*	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd2, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd3, &line);
	ft_putendl(line);
	get_next_line(fd2, &line);
	ft_putendl(line);
	get_next_line(fd2, &line);
	ft_putendl(line);
	get_next_line(fd3, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd3, &line);
	ft_putendl(line);*/
	return (0);
}
