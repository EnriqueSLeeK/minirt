/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:17 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem_alloc;

	mem_alloc = malloc(size * nitems);
	if (mem_alloc == 0)
		return (0);
	ft_bzero(mem_alloc, size * nitems);
	return (mem_alloc);
}
