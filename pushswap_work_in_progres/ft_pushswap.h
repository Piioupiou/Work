/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 23:02:54 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/29 23:28:13 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

typedef struct		s_1list
{
	int				data;
	struct s_1list	*next;
}					t_1list;

t_1list	*ft_pushswap2(t_1list *tmp, t_1list *tmp2, t_1list *tmp3, t_1list *l_b);
void	ft_pushswap(t_1list *l_a);
int		ft_createlst(int argc, char **argv);
int		ft_check(t_1list *l_a);

#endif	/* FT_PUSHSWAP */
