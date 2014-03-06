/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 04:00:34 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/30 03:42:56 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mallocstr(size_t *i, char **tabstr, char const *s, char c)
{
	while (s[i[1]] != c && i[1] <= ft_strlen(s))
		i[1]++;
	tabstr[i[2]] = (char *)malloc(sizeof(char *) * (i[1] - i[0]));
	return (tabstr[i[2]]);
}

static char	**ft_malloctabstr(size_t *i, char **tabstr, char const *s, char c)
{
	i[0] = i[1] = i[2] = 0;
	while (i[0] < ft_strlen(s))
	{
		while (s[i[0]] == c)
			i[0]++;
		while (s[i[0]] != c && i[0] < ft_strlen(s))
			i[0]++;
		if (i[0] < ft_strlen(s))
			i[1]++;
	}
	i[0] = 0;
	tabstr = (char **)malloc(sizeof(char **) * i[1] + 1);
	tabstr[0] = ft_mallocstr(i, tabstr, s, c);
	if (i[1] == 0 && s[i[0]] == c)
		tabstr[0] = 0;
	return (tabstr);
}
char		**ft_strsplit(char const *s, char c)
{
	char	**tabstr;
	size_t	i[3];

	tabstr = ft_malloctabstr(i, tabstr, s, c);
	i[0] = i[1] = i[2] = 0;
	if (tabstr[0] == 0)
		return (tabstr);
	while (i[0] <= ft_strlen(s))
	{
		while (s[i[0]] == c)
			i[0]++;
		i[1] = i[0];
		tabstr[i[2]] = ft_mallocstr(i,tabstr, s, c);
		i[1] = 0;
		while (s[i[0]] != c && i[0] <= ft_strlen(s))
		{
			tabstr[i[2]][i[1]] = s[i[0]];
			i[0]++;
			i[1]++;
		}
		tabstr[i[2]][i[1]] = '\0';
		i[2]++;
	}
	tabstr[i[2]] = '\0';
	return (tabstr);
}
