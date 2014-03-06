/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pierrick.gallois.lacroix>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/21 19:13:35 by pgallois          #+#    #+#             */
/*   Updated: 2013/07/22 23:37:17 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	b;

	b = nb;
	if (b < 1)
		return (0);
	if (nb > 1)
		nb  = ft_recursive_factorial(nb - 1);
	nb = b*(nb);
	return (nb);
}
