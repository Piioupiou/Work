/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pierrick.gallois.lacroix>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/23 02:00:01 by pgallois          #+#    #+#             */
/*   Updated: 2013/11/26 03:15:06 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;
	char	*src;

	src = (char*)s2;
	i = 0;
	while (src[i] != '\0')
	{
		s1[i] = src[i];
		i++;
	}
	while (s1[i] != '\0')
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
