/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 06:27:52 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:16:24 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_struct	**ft_creatematr(t_struct **matr, int fd)
{
	char	*line;
	int		i;
	int		j;

	matr = (t_struct **)malloc(20);
	i = 0;
	j = 0;
	line = "";
	while (get_next_line(fd, &line) == 1)
	{
		matr[i] = ft_get_number(ft_strsplit(line,' '));
		i++;
	}
	matr[0]->size_Y = i;
	ft_strdel(&line);
	matr[i] = NULL;
	return (matr);
}

t_image		*ft_init_image(t_image *img, void *mlx)
{
	int	i;
	char *t;

	i = 0;
	img = (t_image *)malloc(5555555);
	img->image = (char *)mlx_new_image(mlx, 1280, 800);
	img->data = mlx_get_data_addr(img->image, &img->bits, &img->sizeline,\
			 &img->endian);
	while (i <= 3)
	{
		t = ft_strjoin(ft_strjoin("textures/t", ft_itoa(i)), ".xpm");
		if ((img->textur[i] = mlx_xpm_file_to_image(mlx, t, &img->width[i],\
						 &img->height[i])) == 0)
			exit(1);
		img->adr_textur[i] = (char *)mlx_get_data_addr(img->textur[i],\
			 &img->bits_text[i],  &img->sizeline_text[i], &img->endian_text[i]);
		i++;
	}
	if ((img->sky = mlx_xpm_file_to_image(mlx, "textures/sky.xpm", &img->width_sky,
			&img->height_sky)) == 0)
		exit(1);
	img->adr_sky = (char *)mlx_get_data_addr(img->sky, &img->bits_sky,\
				 &img->sizeline_sky, &img->endian_sky);
	return (img);
}

void		clear(t_image *image, t_struct **matr)
{
	int		i;
	int		j;
	int		ps;
	int		pd;

	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < 1280)
		{
			if (i > 400)
				ft_putpix_image(image, j, i, 0x333939);
			else
			{
				ps = (int)(image->sizeline_sky * i + (j - (int)matr[0]->player->direction
							 * 12) * (image->bits_sky >> 3));
				pd = image->sizeline * i + j * (image->bits >> 3);
				image->data[pd] = image->adr_sky[ps];
				image->data[pd + 1] = image->adr_sky[ps + 1];
				image->data[pd + 2] = image->adr_sky[ps + 2];
			}
		}
	}
}

t_pproj		*ft_init_pproj(t_pproj *proj)
{
	proj = (t_pproj *)malloc(5);
	proj->x_max = 1280;
	proj->y_max = 800;
	proj->x_center = 1280/2;
	proj->y_center = 800/2;
	proj->ratio_ray = 0;
	return (proj);
}

t_player	*ft_init_player(t_player *player, t_pproj *proj)
{
	player = (t_player *)malloc(50);
	player->height = BLOCK;
	player->fov = 60;
	player->direction = 270;
	player->inertie = player->direction;
	player->len_to_proj = (int)(proj->x_max / tan(PI180 * player->fov/2));
	player->x = 4 * BLOCK;
	player->y = 13 * BLOCK;
	return (player);
}

