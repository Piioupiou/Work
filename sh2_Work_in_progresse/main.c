/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 23:54:52 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/22 00:07:41 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_start(void)
{
	char	*line;

	ft_putstr("?>");
	while (get_next_line(0, &line) != -1)
	{
		ft_putstr("?>");
	}
	return (0);
}

int	main(void)
{
	ft_start();
	return (0);
}
