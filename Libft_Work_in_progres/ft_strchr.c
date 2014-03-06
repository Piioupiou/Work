/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:51:56 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:13:29 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char*)&str[i]);
		i++;
	}
	if (c == 0)
		return ((char*)&str[i]);
	return (NULL);
}
