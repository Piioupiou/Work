/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 03:58:13 by pgallois          #+#    #+#             */
/*   Updated: 2014/02/16 08:15:33 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_point	*ft_normevect(t_point *p)
{
	double	len;
	t_point	*result;

	result = (t_point *)malloc(99);
	len = ft_lenvect(p);
	result->x = p->x / len;
	result->y = p->y / len;
	result->z = p->z / len;
	free(p);
	return (result);
}

double	ft_lenvect(t_point *p1)
{
	double	result;

	result = sqrt(pow(p1->x, 2) + pow(p1->y, 2) + pow(p1->z, 2));
	return (result);
}

t_point	*ft_prodscal_point(t_point *p1, t_point *p2)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = p1->y * p2->z - p1->z * p2->y;
	result->y = p1->z * p2->x - p1->x * p2->z;
	result->z = p1->x * p2->y - p1->y * p2->x;
	return (result);
}

double	ft_scalaire(t_point *p1, t_point *p2)
{
	double i;

	i = (p1->x * p2->x) + (p1->y * p2->y) + (p1->z * p2->z);
	return (i);
}

t_point	*ft_factor_d_point(t_point *p, double i)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = i * p->x;
	result->y = i * p->y;
	result->z = i * p->z;
	return (result);
}

t_point	*ft_add_d_point(t_point *p, double i)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = i + p->x;
	result->y = i + p->y;
	result->z = i + p->z;
	free(p);
	return (result);
}

t_point	*ft_soustract_d_point(t_point *p, double i)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = i - p->x;
	result->y = i - p->y;
	result->z = i - p->z;
	free(p);
	return (result);
}

t_point	*ft_factor_point(t_point *p1, t_point *p2)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = p1->x * p2->x;
	result->y = p1->y * p2->y;
	result->z = p1->z * p2->z;
	free(p1);
	free(p2);
	return (result);
}

t_point	*ft_add_point(t_point *p1, t_point *p2)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = p1->x + p2->x;
	result->y = p1->y + p2->y;
	result->z = p1->z + p2->z;
	free(p2);
	return (result);
}

t_point	*ft_expose_point(t_point *p1, t_point *p2)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = (int)p1->x ^ (int)p2->x;
	result->y = (int)p1->y ^ (int)p2->y;
	result->z = (int)p1->z ^ (int)p2->z;
	free(p1);
	free(p2);
	return (result);
}

t_point	*ft_soustract_point(t_point *p1, t_point *p2)
{
	t_point	*result;

	result = (t_point *)malloc(99);
	result->x = p1->x - p2->x;
	result->y = p1->y - p2->y;
	result->z = p1->z - p2->z;
	free(p2);
	return (result);
}
