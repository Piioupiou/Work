/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 23:00:21 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/21 09:54:55 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <mlx.h>
#define CTE1 0.8
#define CTE2 0.9


typedef struct		s_struct
{
	int		*data;
	int		size;
}					t_struct;

t_struct	**ft_creatematr(int fd);

void	ft_draw(int i, int j, t_struct **matr, void *mlx, void *win);

t_struct	*ft_get_number(char **str)
{
	int			i;
	int			j;
	t_struct	*tmp;

	tmp = malloc(1);
	i = 0;
	while (str[i] != NULL)
		i++;
	tmp->data = malloc(sizeof(int*) * (i));
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

void	ft_putpix(t_struct **matr, void *mlx, void *win)
{
	int			i;
	int			j;

	i = j = 0;
	while (matr[i] != NULL)
	{
		ft_putstr("while 1\n");
		while (j <= matr[i]->size && matr[i]->size != 0)
		{
			ft_putnbr(matr[i]->size);
			ft_putstr("\nWhile 2\n");
		//	if (matr[i]->size != 0)
				ft_draw(i, j, matr, mlx, win);
			j++;
		}
		j = 0;
		i++;
	}
}


void	ft_draw(int i, int j, t_struct **matr, void *mlx, void *win)
{
	double	x2;
	double	y2;
	double	y1;
	double	x1;
	double	x;
	double	y;
	int		color;

	color = 0xFFFFFF;
	if ((j + 1) <= matr[i]->size)
	{
		x = x1 = ((CTE1 * j) - (CTE2 * i)) * 30;
		y = y1 = (matr[i]->data[j] * (-0.1) + ((CTE1/2) * j) + (CTE2/2) * i) * 40;
		x2 = ((CTE1 * (j + 1)) - (CTE2 * (i))) * 30;
		y2 = (matr[i]->data[j + 1] * (-0.1) + ((CTE1/2) * (j + 1)) + (CTE2/2) * i) * 40;
		while (x <= x2 )
		{
			mlx_pixel_put(mlx, win, x + 500, (y1 + (((y2 - y1) * (x - x1)) / (x2 - x1))) + 300, color);
			x++;
	//	color = matr[i]->data[j] * 0xFFFFFF;
		}
	//	color = matr[i]->data[j] * 0xFFFFFF;
		x--;
		while (y <= y2 )
		{
			mlx_pixel_put(mlx, win, (x1 + (((x2 - x1) * (y - y1)) / (y2 - y1))) + 500, y + 300,  color);
	//		color = matr[i]->data[j] * 0xFFFFFF;
			y++;
		}
	//	color = matr[i]->data[j] * 0xFFFFFF;
		y--;
		while (y >= y2 && j != 0)
		{
			mlx_pixel_put(mlx, win, (x1 + (((x2 - x1) * (y - y1)) / (y2 - y1))) + 500, y + 300,  color);
	//		color = matr[i]->data[j] * 0xFFFFFF;
			y--;
		}
	//	color = matr[i]->data[j] * 0xFFFFFF;
	}
	if (matr[i + 1] == NULL)
		return ;
	x1 = ((CTE1 * j) - (CTE2 * i)) * 30;
	x = x1;
	y = y1 = ((matr[i]->data[j] * (-0.1)) + ((CTE1/2) * j) + (CTE2/2) * i) * 40;
	x2 = (((CTE1) * (j)) - ((CTE2) * (i + 1))) * 30;
	y2 = ((matr[i + 1]->data[j] * (-0.1)) + ((CTE1/2) * (j)) + (CTE2/2) * (i + 1)) * 40;
	//color = matr[i]->data[j] * 0xFFFFFF;
	while (y <= y2 && j <= matr[i + 1]->size)
	{
		mlx_pixel_put(mlx, win, (x1 + (((x2 - x1) * (y - y1)) / (y2 - y1))) + 500, y + 300,  color);
	//	color = matr[i]->data[j] * 0xFFFFFF;
		y++;
	}
	//color = matr[i]->data[j] * 0xFFFFFF;
	y--;
	while (y >= y2 && j < matr[i + 1]->size && (j) < matr[i]->size)
	{
		mlx_pixel_put(mlx, win, (x1 + (((x2 - x1) * (y - y1)) / (y2 - y1))) + 500, y + 300,  color);
	//	color = matr[i]->data[j] * 0xFFFFFF;
		y--;
	}
	//color = matr[i]->data[j] * 0xFFFFFF;
	while (x >= x2 && j <= matr[i + 1]->size && matr[i + 1]->size != 0)
	{
		color = (color + ((matr[i]->data[j] + matr[i+1]->data[j])) + 0xFFFFFF + matr[i]->data[j] * 0x000101) & 0xFFFFFF;
		mlx_pixel_put(mlx, win, x + 500, (y1 + (((y2 - y1) * (x - x1)) / (x2 - x1))) + 300, color);
		x--;
	}
}

int		ft_dispmatr(t_struct **matr)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1900, 1080, "fdf");
	ft_putpix(matr, mlx, win);
	mlx_loop(mlx);
	return (1);
}

int		main(int argc, char **argv)
{
	t_struct	**matr;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	matr = ft_creatematr(fd);
	argc++;
	ft_dispmatr(matr);
	return (0);
}

t_struct	**ft_creatematr(int fd)
{
	char		*line;
	t_struct	**matr;
	int			i;
	int			j;

	matr = malloc(1);
	i = j = 0;
	line = "";
	while (get_next_line(fd, &line))
	{
		matr[i] = ft_get_number(ft_strsplit(line,' '));
		ft_putstr("\n------------\n\n");
		i++;
	}
	matr[i] = NULL;
	return (matr);
}

