/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 08:12:52 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/26 10:28:03 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILLER_H
# define FILLER_H

typedef struct		s_struct
{
	int				i;
	int				j;
	char			**tab;
	int				*size_map;
	char			*player;
	int				p;
	int				np;
	char			**piece;
	int				size_p;
}					t_struct;

#endif /* FILLER_H */
