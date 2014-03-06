/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 04:33:20 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:13:32 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*map;

	if (argc != 2 || ft_atoi(argv[1]) > 4 || ft_atoi(argv[1]) < 0)
	{
		ft_putstr_fd("usage : ./wolf3d \"number of the map\"\n", 2);
		return (-1);
	}
	map = ft_strjoin("map/map", argv[1]);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (-1);
	}
	ft_mlx(fd);
	close(fd);
	return (0);
}

void		ft_putpix_image(t_image *img, int x, int y, unsigned long color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF);
	img->data[y * img->sizeline + x * img->bits / 8] = b;
	img->data[y * img->sizeline + x * img->bits / 8 + 1] = g;
	img->data[y * img->sizeline + x * img->bits / 8 + 2] = r;
}

int			ft_expose(t_struct **matr)
{
	char	*A;
	unsigned long color;
	int	i;

	i = matr[0]->i / 100;
	color = 0xFF0000;
	clear(matr[0]->image, matr);
	ft_raycasting(matr[0]->player, matr[0]->pproj, matr, matr[0]->image);
	A = ft_itoa((matr[0]->i)/8);
	color += i * 0x000F00 - i * 0x0F0000;
	if (i > 0)
		mlx_string_put(matr[0]->mlx, matr[0]->win, 1100, 700, color, A);
	else
		mlx_string_put(matr[0]->mlx, matr[0]->win, 1100, 700, 0x000000, A);
	mlx_string_put(matr[0]->mlx, matr[0]->win, 1114, 700, 0xFFFFFF, " Km/h");
	return (0);
}

int			ft_key(t_struct **matr)
{
	double	t;

	t = matr[0]->player->direction;
	matr[0]->player->inertie += fmod((t - matr[0]->player->inertie) * 1.5, 380);
	if (matr[0]->player->turn == 1 && (matr[0]->i > 40 || matr[0]->i < -40))
		matr[0]->player->direction = matr[0]->i > 0 ? t + 0.6 : t - 0.6;
	if (matr[0]->player->turn == 2 && (matr[0]->i > 40 || matr[0]->i < -40))
		matr[0]->player->direction = matr[0]->i < 0 ? t + 0.6 : t - 0.6;
	if (matr[0]->player->turn != 0)
		matr[0]->i = (matr[0]->i > 0) ? matr[0]->i - 1 : matr[0]->i + 1;
	if (matr[0]->player->move == 1)
		matr[0]->i = (matr[0]->i + 2) < 1800 ? matr[0]->i + 9 : 1800;
	else if (matr[0]->player->move == 2)
		matr[0]->i = (matr[0]->i - 4) > -800 ? matr[0]->i - 7 : -800;
	matr[0]->i = (matr[0]->i - 4) > 0 ? matr[0]->i - 4 : matr[0]->i + 4;
	if (matr[0]->i > 0)
		matr = ft_colision_up(matr, matr[0]->i/10);
	else
		matr = ft_colision_down(matr, matr[0]->i/10);
	ft_expose(matr);
	return (1);
}

void		ft_mlx(int fd)
{
	t_struct	**matr = NULL;

	matr = ft_creatematr(matr, fd);
	matr[0]->mlx = mlx_init();
	matr[0]->win = mlx_new_window(matr[0]->mlx, 1280, 800, "Wolf3d");
	matr[0]->i = 0;
	matr[0]->image = ft_init_image(matr[0]->image, matr[0]->mlx);
	matr[0]->pproj = ft_init_pproj(matr[0]->pproj);
	matr[0]->player = ft_init_player(matr[0]->player, matr[0]->pproj);
	clear(matr[0]->image, matr);
	ft_go(matr);
	mlx_do_key_autorepeatoff(matr[0]->mlx);
	mlx_expose_hook(matr[0]->win, ft_expose, matr);
	mlx_hook(matr[0]->win, KeyPress, KeyPressMask, ft_mask, matr);
	mlx_hook(matr[0]->win, KeyRelease, KeyReleaseMask, ft_relaise, matr);
	mlx_loop_hook(matr[0]->mlx, ft_key, matr);
	mlx_loop(matr[0]->mlx);
	ft_freeall(matr);
}

