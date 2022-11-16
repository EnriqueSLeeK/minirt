/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:15 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:15 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	aux;
	long	mode;

	i = 0;
	mode = (long)src - (long)dest;
	if (mode == 0)
		return (dest);
	while (i < n)
	{
		if (mode < 0)
		{
			aux = ((char *)src)[(n - 1) - i];
			((char *)dest)[(n - 1) - i] = aux;
		}
		else
		{
			aux = ((char *)src)[i];
			((char *)dest)[i] = aux;
		}
		i += 1;
	}
	return (dest);
}
