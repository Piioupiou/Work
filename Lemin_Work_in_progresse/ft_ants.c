/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 20:12:39 by pgallois          #+#    #+#             */
/*   Updated: 2014/02/23 22:56:36 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_struct	*ft_sendants(t_struct *e)
{
	int	i;

	i = 0;
	while (i < e->nbant)
	{
		e = ft_moveroad(e, i);
		i++;
	}
	ft_putstr("\n");
	return (e);
}

void		ft_moveants(t_struct *e)
{
	int	i;

	i = 0;
	e->tmp = e->start;
	e->tmp->nbant = e->nbant;
	e->end->nbant = 0;
	ft_putchar('\n');
	e->endant = 0;
	while (e->endant < e->nbant)
		e = ft_sendants(e);
}

t_struct	*ft_initants(t_struct *e)
{
	int	i;
	int	j;

	i = 0;
	j = e->nbant;
	e->tmproad = e->beginroad;
	e->road = e->beginroad;
	e->minroad = e->beginroad;
	while (e->tmproad->next != NULL)
	{
		if (e->minroad->len > e->tmproad->len)
			e->minroad = e->tmproad;
		e->tmproad = e->tmproad->next;
	}
	e->tmproad = e->beginroad;
	e->road = e->beginroad;
	e->road->room = e->road->begin;
	e->ants[i] = (t_ants *)malloc(sizeof(t_room));
	e->ants[i]->pos = (t_room *)malloc(sizeof(t_room) * 2);
	e->ants[i]->nb = i;
	e->ants[i]->pos = e->road->room;
	e->ants[i]->road = e->road;
	e->ants[i]->road->begin = e->road->begin;
	while (e->road->room->next != NULL)
	{
		e->ants[i]->road->room->name = e->road->room->name;
		e->road->room = e->road->room->next;
		e->ants[i]->road->room = e->ants[i]->road->room->next;
	}
	i++;
	while (i < e->nbant)
	{
		if (e->tmproad->len < j)
			e->road = e->tmproad;
		else
			e->road = e->minroad;
		e->road->len--;
		e->road->room = e->road->begin;
		e->ants[i] = (t_ants *)malloc(sizeof(t_room));
		e->ants[i]->pos = (t_room *)malloc(sizeof(t_room) * 2);
		e->ants[i]->nb = i;
		e->ants[i]->pos = e->road->room;
		e->ants[i]->road = (t_road *)malloc(sizeof(t_room *) * 3 + sizeof(t_road *) * 2);
		e->ants[i]->road = e->road;
		j--;
		i++;
		if (e->tmproad != NULL)
			e->tmproad = e->tmproad->next;
		else
			e->tmproad = e->beginroad;
	}
	return (e);
}

