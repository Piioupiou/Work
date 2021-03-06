/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 23:52:51 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/21 09:43:38 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	somme;
	int	i;
	int	signe;

	signe = 1;
	somme = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' '
			|| str[i] == '-' || (str[i] == '+' && ft_isdigit(str[i + 1])))
	{
		if (str[i] == '-')
			signe *= (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
			somme = (somme * 10) + (str[i] - 48);
			i++;
	}
	return (somme * signe);
}
