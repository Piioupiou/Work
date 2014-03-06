/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 06:34:40 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:13:27 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_struct	**ft_colision_up(t_struct **matr, int i)
{
	int		x[4];
	int		y[4];

	y[3] = matr[0]->player->y;
	x[3] = matr[0]->player->x;
	y[0] = (int)(matr[0]->player->y + sin(PI180 * matr[0]->player->inertie)\
			 * -i);
	x[0] = (int)(matr[0]->player->x + cos(PI180 * matr[0]->player->inertie)\
			 * i);
	y[1] = (int)(matr[0]->player->y + sin(PI180 * (matr[0]->player->inertie\
					 + 30)) * (-310 - i));
	x[1] = (int)(matr[0]->player->x + cos(PI180 * (matr[0]->player->inertie\
					 + 30)) * (310 + i));
	y[2] = (int)(matr[0]->player->y + sin(PI180 * (matr[0]->player->inertie\
					 - 30)) * (-310 - i));
	x[2] = (int)(matr[0]->player->x + cos(PI180 * (matr[0]->player->inertie\
					 - 30)) * (310 + i));
	if (((int)(matr[matr[0]->player->x/BLOCK]->data[y[1]/BLOCK] != 1)
				&& (int)(matr[matr[0]->player->x/BLOCK]->data[y[2]/BLOCK] != 1))
			&& (int)(matr[matr[0]->player->x/BLOCK]->data[y[0]/BLOCK] != 1))
		matr[0]->player->y = y[0];
	else
		matr[0]->i = -i * 3 + 50;
	return (ft_colision_up2(x, y, matr, i));
}

t_struct	**ft_colision_up2(int *x, int *y, t_struct **matr, int i)
{
	if (((int)(matr[x[1]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1)
				&& (int)(matr[x[2]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1))
			&& (int)(matr[x[0]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1))
		matr[0]->player->x = x[0];
	else
		matr[0]->i = -i * 3 + 50;
	if (matr[matr[0]->player->x/BLOCK]->data[matr[0]->player->y/BLOCK] == 1)
	{
		if (matr[matr[0]->player->x/BLOCK]->data[y[3]/BLOCK] != 1)
			matr[0]->player->y = y[3];
		else if (matr[x[3]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1)
			matr[0]->player->x = x[3];
		else
		{
			matr[0]->player->x = x[3];
			matr[0]->player->y = y[3];
		}
	}
	return (matr);
}

t_struct	**ft_colision_down(t_struct **matr, int i)
{
	int		x[4];
	int		y[4];

	y[3] = matr[0]->player->y;
	x[3] = matr[0]->player->x;
	x[0] = (int)(matr[0]->player->x - cos(PI180 * matr[0]->player->inertie)
			 * -i);
	y[0] = (int)(matr[0]->player->y - sin(PI180 * matr[0]->player->inertie)\
			 * i);
	x[1] = (int)(matr[0]->player->x - cos(PI180 * (matr[0]->player->direction\
					 + 210)) * (310 + i));
	y[1] = (int)(matr[0]->player->y - sin(PI180 * (matr[0]->player->direction\
					 + 210)) * (-310 - i));
	x[2] = (int)(matr[0]->player->x - cos(PI180 * (matr[0]->player->direction\
					 - 210)) * (310 + i));
	y[2] = (int)(matr[0]->player->y - sin(PI180 * (matr[0]->player->direction\
					 - 210)) * (-310 - i));
	if (((int)(matr[matr[0]->player->x/BLOCK]->data[y[1]/BLOCK] != 1)
				&& (int)(matr[matr[0]->player->x/BLOCK]->data[y[2]/BLOCK] != 1))
			&& (int)(matr[matr[0]->player->x/BLOCK]->data[y[0]/BLOCK] != 1))
		matr[0]->player->y = y[0];
	else
		matr[0]->i = -i * 3 + 50;
	return (ft_colision_down2(x, y, matr, i));
}

t_struct	**ft_colision_down2(int *x, int *y, t_struct **matr, int i)
{
	if (((matr[x[1]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1)
				&& (matr[x[2]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1))
			&& (matr[x[0]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1))
		matr[0]->player->x = x[0];
	else
		matr[0]->i = -i * 3 + 50;
	if (matr[matr[0]->player->x/BLOCK]->data[matr[0]->player->y/BLOCK] == 1)
	{
		if (matr[matr[0]->player->x/BLOCK]->data[y[3]/BLOCK] != 1)
			matr[0]->player->y = y[3];
		else if (matr[x[3]/BLOCK]->data[matr[0]->player->y/BLOCK] != 1)
			matr[0]->player->x = x[3];
		else
		{
			matr[0]->player->x = x[3];
			matr[0]->player->y = y[3];
		}
	}
	return (matr);
}

