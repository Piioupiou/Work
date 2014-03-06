/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 01:41:13 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/28 05:08:42 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrevi(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[0] == '-')
		i++;
	while (j > i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
	return (str);
}
static char	*ft_itoa_recurs(int n, int i, char *str)
{
	if ((n / 10) > 0)
		ft_itoa_recurs(n / 10, i + 1, str);
	str[i] = (n % 10 + 48);
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char *) * 20);
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
		i++;
	}
	if (n == -2147483648)
		return ("-2147483648");
	return (ft_strrevi(ft_itoa_recurs(n, i, str)));
}


