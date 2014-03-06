/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 03:33:36 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:10:37 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*str1;
	const char	*str2;
	char		*str3;
	size_t			i;

	str3 = (char *) malloc(sizeof(s1) * n);
	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n)
	{
		str3[i] = str2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		str1[i] = str3[i];
		i++;
	}
	return (s1);
}
