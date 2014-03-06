/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 02:27:11 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/29 09:35:06 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s2;
	size_t	i[3];

	i[0] = i[1] = i[2] = 0;
	while ((s[i[2]] == ' ' || s[i[2]] == '\n' || s[i[2]] == '\t'))
		i[2]++;
	i[0] = ft_strlen(s) - 1;
	while ((s[i[0]] == ' ' || s[i[0]] == '\n' || s[i[0]] == '\t')
			&& i[0] != 0)
	{
		i[0]--;
		i[1]++;
	}
	s2 = (char *)malloc(sizeof(char *) * (ft_strlen(s) - i[2] - i[1] + 1));
	if (s2 == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = i[1] + i[2] + 1;
	while (s[i[0]] != '\0' && i[0] <= ft_strlen(s) - i[1])
	{
		s2[i[0]] = s[i[2]];
		i[0]++;
		i[2]++;
	}
	return (s2);
}
