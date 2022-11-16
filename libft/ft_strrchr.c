/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/10 14:03:46 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			ptr = (char *)&str[i];
		i += 1;
	}
	if (str[i] == (unsigned char)c)
		ptr = (char *)&str[i];
	if (ptr)
		return (ptr);
	return (0);
}
