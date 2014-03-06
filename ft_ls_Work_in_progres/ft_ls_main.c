/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 03:15:43 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/13 06:30:08 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int	ft_ls(char *s, int tmp)
{
	DIR				*dir;
	struct dirent	*sd;

	if ((dir = opendir(s)))
	{
		sd = readdir(dir);
			while (sd != NULL)
			{
				if (sd->d_name[0] != '.' || tmp == 2)
					ft_putendl(sd->d_name);
				sd = readdir(dir);
			}
		closedir(dir);
	}
	else
	{
		ft_putstr("ls: ");
		ft_putstr(s);
		ft_putstr(": ");
		perror((char *)dir);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 1;
	if (argc > 1 && (argv[1][0] == '-' && argv[1][1] == 'a'))
		i = tmp = 2;
	if (argc == 1 || (argc == 2 && tmp == 2))
		ft_ls(".", tmp);
	else
	{
		while (i < argc)
		{
			if ((argc > 2 && tmp == 0) || (argc > 3 && tmp != 0))
			{
				if ((i > 1 && tmp == 0) || (i > 2 && tmp != 0 ))
					ft_putchar('\n');
				ft_putstr(argv[i]);
				ft_putendl(":");
			}
			ft_ls(argv[i], tmp);
			i++;
		}
	}
	return (1);
}

