/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 20:10:56 by pgallois          #+#    #+#             */
/*   Updated: 2014/03/04 18:24:53 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_struct	*ft_match(t_struct *e)
{
	char	*str;

	str = e->tmp->pipe->name;
	e->tmp = e->beginlist;
	while (ft_strcmp(str, e->tmp->name) != 0)
	{
		ft_putendl(e->tmp->name);
		e->tmp = e->tmp->next;
		if (e->tmp->next == NULL)
		{
			ft_putstr("ERROR");
			exit(1);
		}
	}
	return (e);
}

t_road		*ft_recursfindroad(t_struct *e, t_road	*road)
{
	while (e->tmp->pipe != NULL)
	{
		e->tmp2 = e->tmp;
		e->tmp->pipe = e->tmp->beginpipe;
		while (e->tmp->pipe != NULL && e->tmp->pipe->use == 1)
			e->tmp->pipe = e->tmp->pipe->next;
		if (e->tmp->pipe == NULL)
				return (NULL);
		e->tmp->pipe->use = 1;
		if (e->tmp->pipe->name == NULL)
			return (NULL);
		e = ft_match(e);
		e->tmp2->pipe = e->tmp2->beginpipe;
		road->tmproom = (t_room *)malloc(sizeof(t_room *) * 3);
		road->tmproom->name = e->tmp->name;
		road->tmproom->take = -42;
		road->tmproom->next = road->room;
		road->room->prev = road->tmproom;
		road->tmproom = road->tmproom->prev;
		road->room = road->room->prev;
		road->len++;
		if (e->tmp->start == 1)
			return (e->road);
		e->road = ft_recursfindroad(e, road);
		if (e->road != NULL)
			return (e->road);
	}
	return (NULL);
}

t_road	*ft_initroad(t_struct *e)
{
	e->road = (t_road *)malloc(sizeof(t_room *) * 3 + sizeof(t_road *) * 2);
	e->road->room = (t_room *)malloc(sizeof(t_room *) * 2);
	e->road->room->prev = (t_room *)malloc(sizeof(t_room *) * 2);
	e->road->begin = (t_room *)malloc(sizeof(t_room *) * 2);
	e->road->room->name = e->tmp->name;
	e->road->tmproom = (t_room *)malloc(sizeof(t_room) * 2);
	e->road->room->prev = e->road->tmproom;
	e->road->len = 0;
	return (e->road);
}

t_struct	*ft_findroad(t_struct *e)
{
	e->end->pipe = e->end->beginpipe;
	e->tmp = e->end;
	e->road = ft_initroad(e);
//	e->road = ft_recursfindroad(e, e->road);
	e->beginroad = e->road;
//	e->road = e->road->next;
	while ((e->road = ft_recursfindroad(e, e->road)) != NULL)
	{
		e->road->next = ft_initroad(e);
		ft_putstr_fd("\nBOUCLE", 2);
		e->road = e->road->next;
		e->road = ft_initroad(e);
	}
	e->road = e->beginroad;
	if (e->road == NULL)
	{
		ft_putstr_fd("\nERROR", 2);
		exit(1);
	}
	e->road->begin = e->road->room;
	e->road->room = e->road->begin;
	return (e);

}

t_struct	*ft_moveroad(t_struct *e, int i)
{
	e->road = e->ants[i]->road;
	e->road->room = e->road->begin;
	while (ft_strcmp(e->ants[i]->road->room->name, e->ants[i]->pos->name) != 0)
	{
		if (e->road->room == NULL)
			return (e);
		e->road->room = e->road->room->next;
	}
	if (e->ants[i]->pos->next == NULL)
		e->endant++;
	if (e->ants[i]->pos == NULL)
		return (e);
	if (e->ants[i]->pos->next == NULL || (e->road->room->next->take != -42
				&& e->road->room->take != e->ants[i]->nb))
		return (e);
	e->road->room->take = -42;
	e->ants[i]->pos = e->ants[i]->pos->next;
	e->road->room->next->take = i;
	ft_putstr("L");
	ft_putnbr(i + 1);
	ft_putstr("-");
	ft_putstr(e->ants[i]->pos->name);
	if (i < e->nbant)
		ft_putchar(' ');
	return (e);
}

