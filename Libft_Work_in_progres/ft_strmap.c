/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 06:59:07 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/28 07:33:06 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(s) * sizeof(f) + 1);
	while (s[i] != '\0')
	{
		s2[i] = f((char)s[i]);
		i++;
	}
	return (s2);
}
