/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:40:38 by pgallois          #+#    #+#             */
/*   Updated: 2014/03/25 04:01:30 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	free_all(t_struct *e)
{
	free(e->constV1);
	free(e->constV2);
	free(e->constV3);
	free(e->D);
	free(e->lum->L);
	free(e->sphere->o);
	free(e->cam->direction);
	free(e->cam->HGvue);
	free(e->cam->H);
	free(e->cam->V);
	free(e->cam->U);
	free(e->cam->D);
	free(e->lum);
	free(e->sphere);
	free(e->cam);
	free(e);
}

int		send_key(int key)
{
	if (key == 65307)
		exit (0);
	return (0);
}

t_color *ft_colorhexa_to_tcolor(unsigned long hcolor)
{
	t_color	*color;

	color = malloc(9999);
	color->r = ((hcolor & 0xFF0000) >> 16) / 255;
	color->g = ((hcolor & 0xFF00) >> 8) / 255;
	color->b = (hcolor & 0xFF) / 255;
	ft_putnbr((int)color->r);
	ft_putchar('\n');
	ft_putnbr((int)color->g);
	ft_putchar('\n');
	ft_putnbr((int)color->b);
	ft_putchar('\n');
	return (color);
}

void	ft_putpix_image(t_image *img, int x, int y, t_color *color)
{
	img->data[y * img->sizeline + x * img->bits / 8] = (unsigned char)(color->b * 255);
	img->data[y * img->sizeline + x * img->bits / 8 + 1] = (unsigned char)(color->g * 255);
	img->data[y * img->sizeline + x * img->bits / 8 + 2] = (unsigned char)(color->r * 255);
}
