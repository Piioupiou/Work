/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:40:38 by pgallois          #+#    #+#             */
/*   Updated: 2014/02/16 08:10:45 by pgallois         ###   ########.fr       */
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

void	ft_putpix_image(t_image *img, int x, int y, unsigned long color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	img->data[y * img->sizeline + x * img->bits / 8] = b;
	img->data[y * img->sizeline + x * img->bits / 8 + 1] = g;
	img->data[y * img->sizeline + x * img->bits / 8 + 2] = r;
}
