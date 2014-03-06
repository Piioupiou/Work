/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:31:08 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 04:29:36 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str[2];
	size_t	i[2];

	str[0] = (char*) s1;
	str[1] = (char*) s2;
	i[0] = i[1] = 0;
	if (ft_strlen(str[1]) == 0)
		return (str[0]);
	while (str[0][i[1]] != '\0' && n != 0)
	{
		while (str[0][i[1]] == str[1][i[0]] && str[1][i[0]] != '\0' && n != 0)
		{
			i[0]++;
			i[1]++;
			if (i[0] == ft_strlen(str[1]))
				return (&str[0][i[1] - i[0]]);
			n--;
		}
		i[1] = i[1] - i[0];
		i[0] = 0;
		i[1]++;
		n--;
	}
	return (NULL);
}
