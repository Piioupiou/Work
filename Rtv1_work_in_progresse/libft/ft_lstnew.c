/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 05:58:50 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/22 13:06:46 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*cpcontent;
	size_t	cpsize;
	t_list	*new;

/*	cpcontent = malloc(content_size);*/
	cpcontent = (void*)content;
	cpsize = content_size;
	new = (void*)malloc(cpsize);
	if (cpcontent == NULL)
		return (NULL);
	new->content = cpcontent;
	new->content_size = cpsize;
	new->next = 0;
	return (new);
}
