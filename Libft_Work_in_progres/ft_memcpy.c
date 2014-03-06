/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 01:46:02 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:10:11 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*str1;
	const char	*str2;
	int			i;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (n != 0)
	{
		str1[i] = str2[i];
		i++;
		n--;
	}
	return (s1);
}
