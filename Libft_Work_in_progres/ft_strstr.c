/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:38:08 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 04:29:55 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str[2];
	size_t	i[2];

	str[0] = (char*) s1;
	str[1] = (char*) s2;
	i[0] = i[1] = 0;
	if (ft_strlen(str[1]) == 0)
		return (str[0]);
	while (str[0][i[1]] != '\0')
	{
		while (str[0][i[1]] == str[1][i[0]] && str[1][i[0]] != '\0')
		{
			i[0]++;
			i[1]++;
			if (i[0] == ft_strlen(str[1]))
				return (&str[0][i[1] - i[0]]);
		}
		i[1] = i[1] - i[0];
		i[0] = 0;
		i[1]++;
	}
	return (NULL);
}
