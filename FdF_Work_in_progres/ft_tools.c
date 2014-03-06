/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:40:38 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/22 21:39:27 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_struct	*ft_get_number(char **str)
{
	int			i;
	int			j;
	t_struct	*tmp;

	tmp = (t_struct *)malloc(1);
	tmp->data = (int *)malloc(sizeof(int*) * 9999999999);
	i = j = 0;
	while (str[i] != NULL)
	{
		while ((ft_atoi(str[i]) != 0 || ft_strcmp(str[i],"0")
					|| ft_strcmp(str[i], "-") || ft_strcmp(str[i], "+"))
				&& str[i + 1] != NULL && ft_strcmp(str[i], ";") != 0)
		{
			tmp->data[j] = ft_atoi(str[i]);
			j++;
			i++;
		}
		i++;
	}
	ft_strdel(str);
	tmp->size = j;
	return (tmp);
}

void		ft_putpix(t_struct **matr)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (matr[i] != NULL)
	{
		while (j <= matr[i]->size && matr[i]->size != 0)
		{
			if (j < matr[i]->size)
				ft_draw_x(i, j, matr);
			if (matr[i + 1] != NULL)
				ft_draw_y(i, j, matr);
			j++;
		}
		j = 0;
		i++;
	}
}


void		ft_draw_x(int i, int j, t_struct **matr)
{
	t_iso	iso;

	iso.color = 0xFFFFFF;
	iso.x1 = ((CTE1 * j) - (CTE2 * i)) * X;
	iso.x = iso.x1;
	iso.y1 = (matr[i]->data[j] * (Z) + ((CTE1/2) * j)\
			+ (CTE2/2) * i) * Y;
	iso.y = iso.y1;
	iso.x2 = ((CTE1 * (j + 1)) - (CTE2 * (i))) * X;
	iso.y2 = (matr[i]->data[j + 1] * (Z) + ((CTE1/2) * (j + 1))\
			+ (CTE2/2) * i) * Y;
	while (++iso.x <= iso.x2)
		mlx_pixel_put(matr[0]->mlx, matr[0]->win, iso.x + 500, (iso.y1 + ((iso.y2\
							- iso.y1) * (iso.x - iso.x1)) / (iso.x2 - iso.x1))\
				+ 300, iso.color);
	while (++iso.y <= iso.y2)
		mlx_pixel_put(matr[0]->mlx, matr[0]->win, (iso.x1 + ((iso.x2 - iso.x1)\
						* (iso.y - iso.y1)) / (iso.y2 - iso.y1)) + 500, iso.y\
				+ 300,  iso.color);
	iso.y--;
	while (j != 0 && iso.y2 <= --iso.y)
		mlx_pixel_put(matr[0]->mlx, matr[0]->win, (iso.x1 + ((iso.x2- iso.x1)\
						* (iso.y - iso.y1)) / (iso.y2 - iso.y1)) + 500, iso.y\
				+ 300,  iso.color);
}

void		ft_draw_y(int i, int j, t_struct **matr)
{
	t_iso	iso;

	iso.color = 0xFFFFFF;
	iso.x1 = ((CTE1 * j) - (CTE2 * i)) * X;
	iso.x = iso.x1;
	iso.y1 = ((matr[i]->data[j] * (Z)) + ((CTE1/2) * j)\
			+ (CTE2/2) * i) * Y;
	iso.y = iso.y1;
	iso.x2 = (((CTE1) * (j)) - ((CTE2) * (i + 1))) * X;
	iso.y2 = ((matr[i + 1]->data[j] * (Z)) + ((CTE1/2) * (j))\
			+ (CTE2/2) * (i + 1)) * Y;
	while (iso.y2 >= ++iso.y && j < matr[i + 1]->size)
		mlx_pixel_put(matr[0]->mlx, matr[0]->win, (iso.x1 + ((iso.x2 - iso.x1)\
						* (iso.y - iso.y1)) / (iso.y2 - iso.y1)) + 500, iso.y\
				+ 300,  iso.color);
	iso.y--;
	while (--iso.y >= iso.y2 && j < matr[i + 1]->size && (j) < matr[i]->size)
		mlx_pixel_put(matr[0]->mlx, matr[0]->win, (iso.x1+ ((iso.x2 - iso.x1)\
						* (iso.y - iso.y1)) / (iso.y2 - iso.y1)) + 500, iso.y\
				+ 300, iso.color);
	while (--iso.x >= iso.x2 && j <= matr[i + 1]->size && matr[i + 1]->size != 0)
		mlx_pixel_put(matr[0]->mlx, matr[0]->win, iso.x + 500, (iso.y1\
					+ (((iso.y2 - iso.y1) * (iso.x - iso.x1))\
						/ (iso.x2- iso.x1))) + 300, iso.color);
}

