/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:15 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/08 22:27:52 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*str_1;
	const unsigned char	*str_2;
	size_t				i;

	i = 0;
	str_1 = (const unsigned char *)str1;
	str_2 = (const unsigned char *)str2;
	while (i < n && str_1[i] == str_2[i])
	{
		i += 1;
	}
	if (i == n)
		return (0);
	return (str_1[i] - str_2[i]);
}
