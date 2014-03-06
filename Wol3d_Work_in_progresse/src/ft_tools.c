/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:40:38 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:13:35 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_go(t_struct **matr)
{
	ft_expose(matr);
	mlx_string_put(matr[0]->mlx, matr[0]->win, 600, 200, 0xFF0000, "3");
	sleep(1);
	ft_expose(matr);
	mlx_string_put(matr[0]->mlx, matr[0]->win, 600, 200, 0xBB5500, "2");
	sleep(1);
	ft_expose(matr);
	mlx_string_put(matr[0]->mlx, matr[0]->win, 600, 200, 0x55BB00, "1");
	sleep(1);
	ft_expose(matr);
	mlx_string_put(matr[0]->mlx, matr[0]->win, 600, 200, 0x00FF00, "GO !!");
	sleep(1);
}

void		ft_freeall(t_struct **matr)
{
	int			i;

	i  = 0;
	while (matr[i] != NULL)
	{
		free(matr[i]->data);
		free(matr[i]);
		i++;
	}
	free(matr[0]->image);
	free(matr[0]->pproj);
	free(matr[0]->player);
	free(matr);
}

int			ft_mask(int key, t_struct **matr)
{
	if (key == 65307)
	{
		ft_freeall(matr);
		exit (0);
	}
	if (key == 65361)
		matr[0]->player->turn = 1;
	if (key == 65363)
		matr[0]->player->turn = 2;
	if (key == 65362)
		matr[0]->player->move = 1;
	if (key == 65364)
		matr[0]->player->move = 2;
	ft_expose(matr);
	return (0);
}

int			ft_relaise(int key, t_struct **matr)
{
	if (key == 65307)
		exit (0);
	if (key == 65361)
		matr[0]->player->turn = 0;
	if (key == 65363)
		matr[0]->player->turn = 0;
	if (key == 65362)
		matr[0]->player->move = 0;
	if (key == 65364)
		matr[0]->player->move = 0;
	ft_expose(matr);
	return (0);
}

t_struct	*ft_get_number(char **str)
{
	int			i;
	int			j;
	t_struct	*tmp;

	tmp = (t_struct *)malloc(1);
	tmp->data = (int *)malloc(sizeof(int*) * 2900000);
	i = j = 0;
	while (str[i] != NULL)
	{
		while ((ft_atoi(str[i]) != 0 || ft_strcmp(str[i],"0")
					|| ft_strcmp(str[i], "-") || ft_strcmp(str[i], "+"))
				 && ft_strcmp(str[i], ";") != 0)
		{
			tmp->data[j] = ft_atoi(str[i]);
			j++;
			i++;
			if (str[i] == NULL)
				break ;
		}
		i++;
	}
	tmp->size_X = j;
	return (tmp);
}

