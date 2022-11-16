/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/10 22:18:06 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dst == src && !dst)
		return (src_size);
	if (size == 0)
		return (src_size);
	while (i < src_size && i < size - 1)
	{
		if (i < src_size)
			dst[i] = src[i];
		else
			dst[i] = 0;
		i += 1;
	}
	if (size - 1 < src_size)
		dst[i] = 0;
	if (!(i < src_size))
		dst[i] = '\0';
	return (src_size);
}
