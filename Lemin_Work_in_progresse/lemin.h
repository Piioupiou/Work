/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 10:13:45 by pgallois          #+#    #+#             */
/*   Updated: 2014/02/23 23:05:45 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	struct s_room	*next;
	struct s_room	*prev;
	int				take;
}					t_room;

typedef struct		s_map
{
	char			*name;
	struct s_map	*next;
	struct s_map	*beginpipe;
	struct s_map	*pipe;
	struct s_map	*tmppipe;
	int				use;
	int				start;
	int				nbant;
}					t_map;

typedef struct		s_road
{
	t_room			*begin;
	t_room			*room;
	t_room			*tmproom;
	struct s_road	*next;
	int				len;
}					t_road;

typedef struct		s_ants
{
	t_room			*pos;
	t_road			*road;
	int				nb;
}					t_ants;

typedef struct		s_struct
{
	int				nbant;
	int				endant;
	t_ants			**ants;
	t_road			*road;
	t_road			*beginroad;
	t_road			*tmproad;
	t_road			*minroad;
	t_map			*tmp;
	t_map			*tmp2;
	t_map			*end;
	t_map			*start;
	t_map			*beginlist;
}					t_struct;

t_struct	*ft_init_start(t_struct *e, char *line);
t_struct	*ft_parse2(t_struct *e, char *line);
void		ft_parse(t_struct *e);
t_struct	*ft_match(t_struct *e);
t_road		*ft_recursfindroad(t_struct *e, t_road	*road);
t_struct	*ft_findroad(t_struct *e);
t_struct	*ft_moveroad(t_struct *e, int i);
t_struct	*ft_sendants(t_struct *e);
void		ft_moveants(t_struct *e);
t_struct	*ft_initants(t_struct *e);
void		ft_lemin(t_struct *e);
t_struct	*ft_jonction2(t_struct *e, char *r2);
t_struct	*ft_jonction(char *r1, char *r2, t_struct *e);
void		ft_tube(char *line, t_struct *e);

#endif /* LEMIN_H */
