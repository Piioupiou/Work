/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 07:27:11 by pgallois          #+#    #+#             */
/*   Updated: 2014/03/25 03:00:28 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_image		*ft_init_image(t_image *img, void *mlx)
{
	int	i;

	i = 0;
	img = (t_image *)malloc(5555885);
	img->image = malloc(999999);
	img->image = (char *)mlx_new_image(mlx, 800, 600);
	img->data = mlx_get_data_addr(img->image, &img->bits, &img->sizeline,\
			&img->endian);
	return (img);
}

t_struct		*ft_init_cam2(t_struct *e)
{
	e->cam->HGvue = ft_add_point(ft_factor_d_point(e->cam->U,
				e->cam->dist_vue), (ft_factor_d_point(e->cam->H,
						e->cam->long_vue/2.0)));
	e->cam->HGvue = ft_soustract_point(e->cam->HGvue,
			ft_factor_d_point(e->cam->D, (e->cam->larg_vue/2.0)));
	e->constV2 = ft_factor_d_point(e->cam->D, (e->cam->larg_vue/480));
	e->constV3 = ft_factor_d_point(e->cam->H, (e->cam->long_vue/640));
	e->lum = (t_lum *)malloc(99);
	e->lum->L = (t_point *)malloc(99);
	e->lum->o = (t_point *)malloc(99);
	e->lum->o->x = 18;
	e->lum->o->y = 5;
	e->lum->o->z = 0;
	e->lum->L = ft_soustract_point(e->sphere->o, e->lum->o);
	return (e);
}

t_struct		*ft_init_cam(t_struct *e, char **tmp)
{
	e->cam = (t_cam *)malloc(99);
	e->cam->pos = (t_point *)malloc(99);
	e->cam->U = (t_point *)malloc(99);
	e->cam->H = (t_point *)malloc(99);
	e->cam->direction = (t_point *)malloc(99);
	e->cam->V = (t_point *)malloc(99);
	e->cam->D = (t_point *)malloc(99);
	e->cam->HGvue = (t_point *)malloc(99);
	e->cam->pos->x = (double)ft_atoi(tmp[2]);
	e->cam->pos->y = (double)ft_atoi(tmp[4]);
	e->cam->pos->z = (double)ft_atoi(tmp[6]);
	e->cam->direction->x = (double)ft_atoi(tmp[8]);
	e->cam->direction->y = (double)ft_atoi(tmp[9]);
	e->cam->direction->z = (double)ft_atoi(tmp[10]);
	e->cam->dist_vue = 0.6;
	e->cam->long_vue = 0.35;
	e->cam->larg_vue = 0.5;
	e->cam->fov = ft_atoi(tmp[12]);
	e->cam->H->x = 0.0;
	e->cam->H->y = 0.0;
	e->cam->H->z = 1.0;
	e->cam->U = ft_soustract_point(e->cam->direction, e->cam->pos);
	e->cam->D = ft_prodscal_point(e->cam->U, e->cam->H);
	e->cam->H = ft_prodscal_point(e->cam->U, e->cam->D);
	return (ft_init_cam2(e));
}

t_struct	*ft_init_sphere(t_struct *e, char **tmp)
{
	e->sphere = (t_sphere *)malloc(99);
	e->sphere->o = (t_point *)malloc(99);
	e->sphere->o->x = (double)ft_atoi(tmp[2]);
	e->sphere->o->y = (double)ft_atoi(tmp[4]);
	e->sphere->o->z = (double)ft_atoi(tmp[6]);
	e->sphere->r = (double)ft_atoi(tmp[8]);
	e->sphere->color = ft_colorhexa_to_tcolor(0xFF0101);
	return (e);
}

t_struct	*ft_init(int fd, t_struct *e)
{
	char	*line;
	char	**tmp;

	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		if (ft_strcmp(tmp[0], "camera:") == 0)
			e = ft_init_cam(e, tmp);
		else if (ft_strcmp(tmp[0], "sphere:") == 0)
			ft_init_sphere(e, tmp);
		else if (ft_strcmp(tmp[0], "sizemap:") == 0)
		{
			e->map[0] = ft_atoi(tmp[1]);
			e->map[1] = ft_atoi(tmp[2]);
			e->map[2] = ft_atoi(tmp[3]);
		}
	}
	e->lum->color = ft_colorhexa_to_tcolor(0xFFFFFF);
	e->black = ft_colorhexa_to_tcolor(0x000000);
	e->white = ft_colorhexa_to_tcolor(0xFFFFFF);
	e->image = ft_init_image(e->image, e->mlx);
	return (e);
}

