/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 04:00:34 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/30 01:58:06 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**tabstr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		if (i < ft_strlen(s))
			j++;
	}
	tabstr = (char **)malloc(sizeof(char **) * j + 1);
	tabstr[0] = (char *)malloc(sizeof(char *) * ft_strlen(s));
	if (j == 0 && s[i - 1] == c)
	{
		tabstr[0] = 0;
		return (tabstr);
	}
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && j <= ft_strlen(s))
			j++;
		tabstr[k] = (char *)malloc(sizeof(char *) * (j - i));
		if (tabstr[k] == NULL)
			return (NULL);
		j = 0;
		while (s[i] != c && i <= ft_strlen(s))
		{
			tabstr[k][j] = s[i];
			i++;
			j++;
		}
		tabstr[k][j] = '\0';
		k++;
	}
	tabstr[k] = '\0';
	return (tabstr);
}
