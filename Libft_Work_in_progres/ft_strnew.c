/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 06:00:33 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/28 23:26:00 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*a;
	size_t		i;

	i = 0;
	a = (char *)malloc(size + 1);
	if (!a)
	{
		return (NULL);
	}
	while (i <= size )
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
