/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 05:29:50 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/31 06:50:40 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <errno.h>
#include "ft_pipex.h"

int			ft_pipex_error(char **argv, int argc, int *fd, int *pfd)
{
	int		i;

	i = 0;
	if (pipe(pfd) == -1)
	{
		ft_putendl(ft_strjoin("pipex :", strerror(errno)));
		i += 1;
	}
	if (fd[0] == -1 && argc >= 2)
	{
		ft_putendl(ft_strjoin("pipex: ", ft_strjoin(ft_strjoin(\
							strerror(errno), ": "), argv[1])));
		i += 2;
	}
	if (fd[1] == -1 && argc >= 5)
	{
		ft_putendl(ft_strjoin("pipex: ", ft_strjoin(ft_strjoin(\
							strerror(errno), ": "), argv[4])));
		i += 3;
	}
	return (i);
}

int			ft_pipex_error2(int argc, t_data d, char **argv)
{
	int		i;

	i = 0;
	if (argc > 5)
	{
		ft_putendl("pipex: too many arguments");
		i += 4;
	}
	if (argc < 5)
	{
		ft_putendl("pipex: too few arguments");
		i += 5;
	}
	if (d.cmd_path1 == NULL && argc >= 4)
	{
		ft_putendl(ft_strjoin("pipex: command not found: ", argv[3]));
		i += 6;
	}
	if (d.cmd_path2 == NULL && argc >= 3)
	{
		ft_putendl(ft_strjoin("pipex: command not found: ", argv[2]));
		i += 7;
	}
	return (i);
}
