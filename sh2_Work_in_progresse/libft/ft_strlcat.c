/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:53:44 by pgallois          #+#    #+#             */
/*   Updated: 2013/12/22 13:04:44 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] != '\0')
		len++;
	i = 0;
	if (len >= size && len >= ft_strlen((char*)src))
		return (size + ft_strlen((char*)src));
	else if (len >= size && len <= ft_strlen((char*)src))
		return (size + 3 + len);
	while (i < size  - len - 1)
	{
		dst[i + len] = src[i];
		i++;
	}
	if (i > ft_strlen(dst))
		dst[i] = '\0';
	return (len + ft_strlen((char *)src));
}
