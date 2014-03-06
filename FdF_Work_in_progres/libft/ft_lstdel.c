/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 06:47:26 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/01 06:58:16 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**alst2;

	alst2 = alst;
	while (alst[0]->next != NULL)
	{
		del(alst[0]->content, alst[0]->content_size);
		free(alst[0]);
		alst[0] = alst[0]->next;
	}
	ft_lstdelone(alst2, del);
	*alst = NULL;
}
