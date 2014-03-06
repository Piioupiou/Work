/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 07:18:01 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/28 07:33:07 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(s) * sizeof(f) + 1);
	while (s[i] != '\0')
	{
		s2[i] = f(i, (char)s[i]);
		i++;
	}
	return (s2);
}
