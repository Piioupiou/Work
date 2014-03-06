/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 02:04:15 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:07:10 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*str1;
	const char		*str2;
	size_t			i;
	char			c1;

	c1 = c;
	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n)
	{
		if (str2[i] == c1)
		{
			str1[i] = str2[i];
			return (&str1[i + 1]);
		}
		str1[i] = str2[i];
		i++;
	}
	return (NULL);
}
