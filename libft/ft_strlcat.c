/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/10 14:31:05 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	siz;
	size_t	end;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	end = ft_strlen(dst);
	if (size < end)
		return (ft_strlen(src) + size);
	siz = end + ft_strlen(src);
	while (end + i < size - 1 && src[i])
	{
		dst[end + i] = src[i];
		i += 1;
	}
	if (((size_t)(end + i)) == size && (size_t)end < size)
		dst[end + i - 1] = '\0';
	else
		dst[end + i] = '\0';
	return (siz);
}
