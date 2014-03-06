/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:10:59 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/06 08:22:15 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putstr("–2147483648");
		return;
	}
	if (i < 0)
	{
		ft_putchar('-');
		ft_putnbr(i * -1);
		return;
	}
	if ((i / 10) > 0)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}
