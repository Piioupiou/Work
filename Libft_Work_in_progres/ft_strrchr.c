/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:05:22 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:20:10 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return ((char *) &str[i]);
		i--;
	}
	return (NULL);
}
