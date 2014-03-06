/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 09:38:39 by pgallois          #+#    #+#             */
/*   Updated: 2014/02/16 08:40:15 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int				ft_expose(t_struct *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->image->image, 0, 0);
	return (0);
}

unsigned long	ft_check_sphere(t_struct *e)
{
	t_point	*OH2;
	double  CH2;
	double	t[5];

	t[4] = ft_scalaire(e->cam->V, e->sphere->o);
	OH2 = ft_factor_d_point(e->cam->V, ft_lenvect(e->sphere->o));
	if (t[4] < 0.0)
		return (0x000000);
	CH2 = pow(ft_lenvect(ft_soustract_point(e->sphere->o, OH2)), 2);
	t[3] = pow(e->sphere->r, 2);
	if (CH2 > t[3])
		return (0x000000);
	t[2] = sqrt(t[3] - CH2);
	t[0] = t[4] + t[2];
	t[1] = t[4] - t[2];
	if (t[1] > 0.0 && t[0] > t[1])
		t[0] = t[1];
	else if (t[0] < 0.0	|| t[1] < 0.0)
		return (0x000000);
	OH2->x = e->cam->pos->x + (e->cam->V->x * t[0]);
	OH2->y = e->cam->pos->y + (e->cam->V->y * t[0]);
	OH2->z = e->cam->pos->z + (e->cam->V->z * t[0]);
	OH2 = ft_normevect(OH2);
	e->sphere->color = 0xFF0000 * (ft_scalaire(e->lum->L, OH2)
					);
	return (e->sphere->color);
}

int				ft_raytracing(t_struct *e)
{
	double				i;
	double				j;
	unsigned long	color;

	i = 0.0;
	j = 0.0;
	color = 0x000000;
	while (i < 640.0)
	{
		while (j < 480.0)
		{
			e->cam->V = ft_add_point(e->cam->HGvue,
					ft_soustract_point(ft_factor_d_point(e->constV2, i),
						ft_factor_d_point(e->constV3, j)));
			color = ft_check_sphere(e);
			ft_putpix_image(e->image, (int)i, (int)j, color);
			j = j + 1.0;
		}
		j = 0.0;
		i = i + 1.0;
	}
	mlx_expose_hook(e->win, ft_expose, e);
	mlx_put_image_to_window(e->mlx, e->win, e->image->image, 0, 0);
	return (0);
}


int				ft_mlx(int fd)
{
	t_struct	*e = NULL;
	void		*mlx;

	e = (t_struct *)malloc(1);
	mlx = mlx_init();
	e->mlx = mlx;
	e->win = mlx_new_window(e->mlx, 640, 480, "RTv1");
	e = ft_init(fd, e);
	ft_raytracing(e);
	free_all(e);
	mlx_key_hook(e->win, send_key, "");
	mlx_loop(e->mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	*map;

	if (argc != 2 || ft_atoi(argv[1]) > 4 || ft_atoi(argv[1]) < 0)
	{
		ft_putstr_fd("usage : ./RTv1 \"number of the map\"\n", 2);
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
