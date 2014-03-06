/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 20:09:38 by pgallois          #+#    #+#             */
/*   Updated: 2014/03/04 21:51:45 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_struct	*ft_init_start(t_struct *e, char *line)
{
	get_next_line(0, &line);
	ft_putendl(line);
	e->start = (t_map *)malloc(sizeof(t_map *) * 3);
	e->tmp->start = 1;
	e->tmp->name = ft_strsplit(line, ' ')[0];
	e->start = e->tmp;
	e->start->start = 1;
	return (e);
}

t_struct	*ft_parse2(t_struct *e, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		ft_init_start(e, line);
	else if (ft_strcmp(line, "##end") == 0)
	{
		get_next_line(0, &line);
		ft_putendl(line);
		e->tmp->name = ft_strsplit(line, ' ')[0];
		e->tmp->start = 0;
		e->end = (t_map *)malloc(sizeof(t_map *) * 3);
		e->end = e->tmp;
	}
	else if (ft_strchr(line, '-') != NULL)
	{
		ft_tube(line, e);
		exit(0);
	}
	else
	{
		e->tmp->name = ft_strsplit(line, ' ')[0];
		e->tmp->start = 0;
	}
	return (e);
}

void		ft_parse(t_struct *e)
{
	char		*line;

//	line = malloc(999999);
	get_next_line(0, &line);
	ft_putendl(line);
	e->nbant = ft_atoi(line);
	e->ants = (t_ants **)malloc(sizeof(t_ants *) * (e->nbant + 1));
	e->tmp = (t_map *)malloc(sizeof(t_map *) * 4);
	e->tmp2 = (t_map *)malloc(sizeof(t_map *) * 4);
	while (get_next_line(0, &line))
	{
		if (e->beginlist == NULL)
			e->beginlist = e->tmp;
		ft_putendl(line);
		if (ft_strcmp(line, "##start")
				|| ft_strcmp(line, "##end") == 0 || line[0] != '#')
			e = ft_parse2(e, line);
		else if (line[0] == '#')
			continue ;
		e->tmp2->next = e->tmp;
		e->tmp2 = e->tmp2->next;
		e->tmp->next = (t_map *)malloc(sizeof(t_map *) * 3);
		e->tmp = e->tmp->next;
	}
	ft_lemin(e);
}

