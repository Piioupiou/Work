/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:33:12 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/31 07:44:19 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3 = "";
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = (char*)malloc(sizeof(char*) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

int		ft_killbackn(char *s, int c)
{
	int		i;

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
	static char		*str = "";
	char			*buf;
	int				a;

	a = BUFF_SIZE;
	while (ft_killbackn(str, '\n') != 1 && a == BUFF_SIZE)
	{
		buf = (char *)malloc(sizeof(int) * (BUFF_SIZE + 1));
		if (buf == NULL)
		{
			return (-1);
		}
		a = read(fd, buf, BUFF_SIZE);
		buf[a] = '\0';
		str = ft_strjoin((char const *)str, buf);
		free(buf);
	}
	ft_killbackn(str, '\n');
	*line = ft_strdup(str);
	str = str + ft_strlen(*line) + 1;
	if (a != BUFF_SIZE && **line == '\0')
		return (0);
	return (1);
}

