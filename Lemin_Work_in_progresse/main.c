/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 23:52:23 by pgallois          #+#    #+#             */
/*   Updated: 2014/03/04 21:52:23 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_lemin(t_struct *e)
{
	e = ft_findroad(e);
	e = ft_initants(e);
	ft_moveants(e);
}

t_struct	*ft_jonction2(t_struct *e, char *r)
{
	if (e->tmp->beginpipe != NULL)
		e->tmp->tmppipe = e->tmp->beginpipe;
	while (e->tmp->tmppipe != NULL)
		e->tmp->tmppipe = e->tmp->tmppipe->next;
	if (e->tmp->beginpipe == NULL)
	{
		e->tmp->pipe = (t_map *)malloc(sizeof(t_map *) * 5);
		e->tmp->beginpipe = e->tmp->tmppipe;
	}
	if (e->tmp->tmppipe == NULL)
		e->tmp->tmppipe = (t_map *)malloc(sizeof(t_map *) * 5);
	e->tmp->tmppipe->name = r;
	e->tmp->tmppipe->start = e->tmp->start;
	e->tmp->tmppipe->use = 0;
	e->tmp->pipe->next = e->tmp->tmppipe;
	e->tmp->pipe = e->tmp->pipe->next;
	e->tmp->tmppipe = e->tmp->pipe;
	if (e->tmp->beginpipe == NULL)
		e->tmp->beginpipe = e->tmp->pipe;
	if (ft_strcmp(e->tmp->name, e->end->name) == 0)
		e->end = e->tmp;
	e->tmp->pipe = e->tmp->beginpipe;
	e->tmp->tmppipe = e->tmp->beginpipe;
	return (e);
}

t_struct	*ft_jonction(char *r1, char *r2, t_struct *e)
{
	while (e->tmp->next != NULL)
	{
		if (e->tmp->beginpipe == NULL)
			e->tmp->tmppipe = NULL;
		else
			e->tmp->tmppipe = e->tmp->beginpipe;
		if (ft_strcmp(e->tmp->name, r1) == 0)
			e = ft_jonction2(e, r2);
		if (ft_strcmp(e->tmp->name, r2) == 0)
			e = ft_jonction2(e, r1);
		e->tmp = e->tmp->next;
	}
	e->tmp = e->beginlist;
	return (e);
}

void		ft_tube(char *line, t_struct *e)
{
	char	**room;

	room = ft_strsplit(line, '-');
	e = ft_jonction(room[0], room[1], e);
	ft_putstr(room[0]);
	ft_putstr("-");
	ft_putendl(room[1]);
	while (get_next_line(0, &line))
	{
		room = ft_strsplit(line, '-');
		e = ft_jonction(room[0], room[1], e);
		ft_putstr(room[0]);
		ft_putstr("-");
		ft_putendl(room[1]);
	}
	e->tmp = e->beginlist;
	while (e->tmp->next != NULL)
	{
		e->tmp->pipe = e->tmp->beginpipe;
		ft_putstr(e->tmp->name);
		ft_putstr("  :");
		while (e->tmp->pipe != NULL)
		{
			ft_putstr(e->tmp->pipe->name);
			ft_putstr(" ,");
			e->tmp->pipe = e->tmp->pipe->next;
		}
		e->tmp = e->tmp->next;
		ft_putstr("\n");
	}
	e->tmp = e->beginlist;
	ft_lemin(e);
}

int			main(void)
{
	t_struct	*e;

	e = (t_struct *)malloc(sizeof(t_ants **) + sizeof(t_road *) * 4
			+ sizeof(t_map *) * 5);
	ft_parse(e);
	return (0);
}
