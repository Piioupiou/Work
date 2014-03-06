/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 06:37:09 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:14:56 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_raycasting(t_player *player, t_pproj *proj,\
		 t_struct **matr, t_image *image)
{
	int		i;
	double	lenght_ray_h;
	double	lenght_ray_v;
	double	alpha[3];

	alpha[2] = (double)player->fov / (double)proj->x_max;
	i = -1;
	alpha[0] = fmod((player->direction + 30), 360);
	alpha[0] = (alpha[0] >= 0 ? alpha[0] : alpha[0] + 360);
	alpha[1] = 30;
	while (++i < proj->x_max)
	{
		lenght_ray_h = ft_check_horizontal(player,  matr, alpha[0]);
		lenght_ray_v = ft_check_vertical(player,  matr, alpha[0]);
		image->i = matr[0]->image->Ax_h;
		if (lenght_ray_v < lenght_ray_h)
		{
			lenght_ray_h = lenght_ray_v;
			image->i = matr[0]->image->Ay_v;
		}
		lenght_ray_h = lenght_ray_h * cos(PI180 * (alpha[1]));
		image = ft_draw_colone(matr, lenght_ray_h, alpha[0], i);
		ft_raycasting2(alpha, player);
	}
	mlx_put_image_to_window(matr[0]->mlx, matr[0]->win, image->image, 0, 0);
}

double		*ft_raycasting2(double *alpha, t_player *player)
{
	alpha[0] = alpha[0] - alpha[2];
	alpha[0] = fmod((alpha[0]), 360);
	alpha[0] = (alpha[0] >= 0 ? alpha[0] : alpha[0] + 360);
	alpha[1] = fmod((player->direction - alpha[0]), 360);
	alpha[1] = (alpha[1] >= 0 ? alpha[1] : alpha[1] + 360);
	return (alpha);
}

int			ft_rotate_text(t_struct **matr, double alpha)
{
	int	i;
	int	j;

	i = 0;
	if (matr[0]->image->i == matr[0]->image->Ay_v)
		i = 1;
	if ((alpha > 90 && alpha < 180))
		j = (i == 1) ? 1 : 0;
	else if ((alpha < 90))
		j = (i == 1) ? 2 : 0;
	else if ((alpha > 270))
		j = (i == 1) ? 2 : 3;
	else if ((alpha < 270 && alpha > 180))
		j = (i == 1) ? 1 : 3;
	return (j);
}
