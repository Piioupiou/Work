/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 21:17:35 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/26 10:39:55 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

int		ft_checkpos(int x,int y, t_struct *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < s->size_p)
	{
		while (s->piece[i][j] != '\0')
		{
			if ((i + x) >= s->size_map[0] || (j + y) >= s->size_map[1]
					|| s->tab[x + i][y + j] == s->np
					|| s->tab[x + i][y + j] == s->np + 32)
				return (0);
			if (s->piece[i][j] == '*' && (s->tab[x + i][y + j] == s->p
						|| s->tab[x + i][y + j] == s->p + 32))
				k++;
			j++;

		}
		j = 0;
		i++;
	}
	return (k);
}

int		ft_ia(t_struct *s)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < s->size_map[0])
	{
		while (y < s->size_map[1])
		{
			if (ft_checkpos(x, y, s) == 1)
			{
				ft_putnbr(x);
				ft_putchar(' ');
				ft_putnbr(y);
				ft_putstr("\n");
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	ft_putendl("0 0");
	return (1);
}

char	**ft_piece(char *s)
{
	char	**piece;
	int		i;
	int		j;

	j = 0;
	i = ft_atoi(ft_strsplit(s, ' ')[1]);
	piece = (char **)malloc(sizeof(char*) * (i + 1));
	while (j != i)
	{
		get_next_line(0, &s);
		piece[j] = s;
		j++;
	}
	return (piece);
}

int		ft_filler(t_struct *s)
{
	char	*l;
	int		i;
	int		j;

	s->tab = (char **)malloc(sizeof(char *) * (s->size_map[0] + 1));
	i = j = 0;
	while (get_next_line(0, &l) == 1)
	{
		if (l[0] == 'P' && l[1] == 'i')
		{
			s->size_p = ft_atoi(ft_strsplit(l, ' ')[1]);
			s->piece = ft_piece(l);
			ft_ia(s);
			free(s->piece);
			get_next_line(0, &l);
			get_next_line(0, &l);
			i = -1;
			j = 0;
		}
		else
			s->tab[i] = ft_strsplit(l, ' ')[1];
		i++;
	}
	return (0);
}

int		main(void)
{
	t_struct	*s;
	char		*l;

	get_next_line(0, &l);
	s->player = ft_strsplit(l, ' ')[2];
	get_next_line(0, &l);
	s->size_map[0] = ft_atoi(ft_strsplit(l, ' ')[1]);
	s->size_map[1] = ft_atoi(ft_strsplit(l, ' ')[2]);
	get_next_line(0, &l);
	if (s->player[1] == '1')
		s->p = 79;
	else if (s->player[1] == '2')
		s->p = 88;
	if (s->player[1] == '1')
		s->np = 88;
	else if (s->player[1] == '2')
		s->np = 79;
	ft_filler(s);
	free(s->piece);
	free(s->tab);
	return (0);
}
