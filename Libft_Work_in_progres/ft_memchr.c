/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 04:28:31 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:07:28 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t		i;
	char		c2;

	c2 = c;
	i = 0;
	str = (char*)s;
	while (i <= n)
	{
		if (str[i] == c2)
			return(&str[i]);
		i++;
	}
	return (NULL);
}
