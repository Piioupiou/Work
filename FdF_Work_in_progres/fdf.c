/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 23:00:21 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/22 21:51:46 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int			ft_expose(t_struct **matr)
{
	ft_putpix(matr);
	return (0);
}

int		send_key(int key)
{
	if (key == 65307)
		exit (0);
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd;

	if (argc < 2)
	{
		ft_putstr_fd("usage : ./fdf file1\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(argv[1]);
		ft_putendl(": No such file or directory");
		return (-1);
	}
	ft_mlx(fd);
	close(fd);
	return (0);
}

void	ft_mlx(int fd)
{
	t_struct	**matr = NULL;
	void		*mlx;
	void		*win;
	int			i[2];

	i[0] = i[1] = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1900, 1080, "fdf");
	matr = ft_creatematr(fd);
	matr[0]->mlx = mlx;
	matr[0]->win = win;
	mlx_expose_hook(matr[0]->win, ft_expose, &matr[0]);
	mlx_key_hook (matr[0]->win, send_key, "");
	mlx_loop(matr[0]->mlx);
	while (matr[i[0]] != NULL)
	{
		while (i[1] <= matr[i[0]]->size)
		{
			free(&matr[i[0]]->data[i[1]]);
			i[1]++;
		}
		free(matr[i[0]]);
		i[0]++;
	}
}

t_struct	**ft_creatematr(int fd)
{
	char		*line;
	t_struct	**matr = NULL;
	int			i;
	int			j;

	matr = (t_struct **)malloc(2000000);
	i = 0;
	j = 0;
	line = "";
	while (get_next_line(fd, &line) == 1)
	{
		matr[i] = ft_get_number(ft_strsplit(line,' '));
		i++;
	}
	ft_strdel(&line);
	matr[i] = NULL;
	return (matr);
}

