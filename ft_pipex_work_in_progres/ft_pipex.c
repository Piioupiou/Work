/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 22:23:54 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/31 07:33:43 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	**ft_getpath(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5))
			return (ft_strsplit(env[i] + 5, ':'));
		ft_putendl("Pipipi");
		i++;
	}
	ft_putendl("caca");
	return (NULL);
}

void	ft_pipexson(int *fd, int *pfd, char *cmd, t_data d)
{
	dup2(pfd[1], 1);
	dup2(fd[0], 0);
	close(pfd[0]);
	execve(d.cmd_path1, ft_strsplit(cmd, ' '), d.env);
}

void	ft_pipexfather(int *fd, int *pfd, char *cmd, t_data d)
{
	dup2(pfd[0], 0);
	dup2(fd[1], 1);
	close(pfd[1]);
	execve(d.cmd_path2, ft_strsplit(cmd, ' '), d.env);
}

char	*ft_execcmd(char *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	if (cmd == NULL)
		return (NULL);
	i = 0;
	if (!access(cmd, X_OK))
		return (cmd);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(cmd_path, ft_strsplit(cmd, ' ')[0]);
		if (!access(cmd_path, X_OK))
			return (cmd_path);
		i++;
	}
	return (NULL);
}

int		main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		pfd[2];
	t_data	d;
	char	**path;
	int		i;

	fd[1] = open(argv[4], O_RDONLY | O_WRONLY | O_TRUNC, 0777);
	fd[0] = open(argv[1], O_RDONLY);
	path = ft_getpath(env);
	if (argc > 3)
		d.cmd_path1 = ft_execcmd(ft_strtrim(argv[3]), path);
	if (argc > 2)
	d.cmd_path2 = ft_execcmd(ft_strtrim(argv[2]), path);
	i = ft_pipex_error2(argc, d, argv);
	i += ft_pipex_error(argv, argc, fd, pfd);
	if (i != 0)
		return (i);
	d.env = env;
	if (!fork())
		ft_pipexson(fd, pfd, argv[3], d);
	else
		ft_pipexfather(fd, pfd, argv[2], d);
	return (0);
}
