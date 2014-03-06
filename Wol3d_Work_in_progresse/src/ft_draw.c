/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 06:22:10 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:13:24 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_image	*ft_draw_colone(t_struct **matr, double lenght1, double alpha, int i)
{
	int		ps;
	int		pd;
	int		y;
	int		a;

	y = -1;
	lenght1 = BLOCK/2 / lenght1 * 2217.02503369;
	a = ft_rotate_text(matr, alpha);
	alpha = 800.0/2 + lenght1/2.0;
	lenght1 = 800.0/2 - lenght1/2.0;
	while (++y + lenght1 < alpha)
	{
		if (y + lenght1 >= 0 && i >= 0 && i < 1280 && y + lenght1 < 800)
		{
			ps = (((y * BLOCK) / ((int)alpha - (int)lenght1)) *\
					matr[0]->image->sizeline_text[a]) + (matr[0]->image->i % 512\
						 * (matr[0]->image->bits_text[a] >> 3));
			pd = (((int)lenght1 + y) * matr[0]->image->sizeline) + ((i)\
					 * (matr[0]->image->bits >> 3));
			matr[0]->image->data[pd] = matr[0]->image->adr_textur[a][ps];
			matr[0]->image->data[pd + 1] = matr[0]->image->adr_textur[a][ps + 1];
			matr[0]->image->data[pd + 2] = matr[0]->image->adr_textur[a][ps + 2];
		}
	}
	return (matr[0]->image);
}

double	ft_check_vertical(t_player *player,\
		 t_struct **matr, double alpha)
{
	int		X[2];
	int		Y[2];

	if (alpha >= 90 && alpha <= 270)
		X[0] = (int)(floor(player->x / BLOCK)) * BLOCK - 1;
	else
		X[0] = (int)(floor(player->x / BLOCK) * BLOCK + BLOCK);
	Y[0] = (int)(player->y + ((player->x - X[0]) * tan(alpha * PI180)));
	Y[1] = (int)(BLOCK * tan(PI180 * alpha));
	if (alpha >= 90 && alpha <= 270)
		X[1] = -BLOCK;
	else
		X[1] = BLOCK;
	if ((alpha >= 0 && alpha < 90 && Y[1] > 0) || (alpha > 270
				&& alpha < 360 && Y[1] < 0))
		Y[1] *= -1;
	return (ft_check_vertical2(matr, player, X, Y));
}

double	ft_check_vertical2(t_struct **matr, t_player *player,\
		 int *X, int *Y)
{
	while ((X[0] / BLOCK) <= matr[0]->size_Y && X[0]/BLOCK >= 0
			&& Y[0]/BLOCK >= 0 && (Y[0] / BLOCK) < matr[2]->size_X)
	{
		if (matr[X[0]/BLOCK]->data[Y[0]/BLOCK] != 0)
			break ;
		Y[0] += Y[1];
		X[0] += X[1];
	}
	matr[0]->image->Ay_v = Y[0];
	return (sqrt(pow(player->x - X[0], 2) + pow(player->y - Y[0], 2)));
}

double	ft_check_horizontal(t_player *player,\
		 t_struct **matr, double alpha)
{
	int		X[2];
	int		Y[2];

	if (alpha <= 180 && alpha >= 0)
		Y[0] = (int)(floor(player->y / BLOCK)) * BLOCK - 1;
	else
		Y[0] = (int)(floor(player->y / BLOCK) * BLOCK + BLOCK);
	X[0] = (int)(player->x + ((player->y - Y[0]) / tan(alpha * PI180)));
	if (alpha <= 180 && alpha >= 0)
		Y[1] = -BLOCK;
	else
		Y[1] = BLOCK;
	X[1] = (int)(BLOCK/tan(PI180 * alpha));
	if ((alpha >= 180 && alpha < 270 && X[1] > 0) || (alpha > 270
				&& alpha < 360 && X[1] < 0))
		X[1] *= -1;
	return (ft_check_horizontal2(matr, player, X, Y));
}

double	ft_check_horizontal2(t_struct **matr, t_player *player,\
		 int *X, int *Y)
{
	while ((X[0]/BLOCK) >= 0 && (Y[0]/BLOCK) >= 0
			&& (X[0] / BLOCK) < matr[0]->size_Y
			&& (Y[0] / BLOCK) <= matr[2]->size_X)
	{
		if (matr[X[0]/BLOCK]->data[Y[0]/BLOCK] != 0)
			break ;
		Y[0] += Y[1];
		X[0] += X[1];
	}
	matr[0]->image->Ax_h = X[0];
	return (sqrt(pow(player->x - X[0], 2) + pow(player->y - Y[0], 2)));
}

