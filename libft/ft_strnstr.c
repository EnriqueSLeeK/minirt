/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/10 23:00:23 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	size_t		i;
	size_t		targ_size;

	targ_size = ft_strlen(target);
	if (str[0])
		;
	if (!(targ_size) || target == 0)
		return ((char *)str);
	if (len < targ_size)
		return (0);
	i = 0;
	while (i < len)
	{	
		if (i < len + 1 - targ_size)
		{
			if (!(ft_strncmp(&str[i], target, targ_size)))
				return ((char *)&str[i]);
		}
		else
			break ;
		if (!(str[i]))
			break ;
		i += 1;
	}
	return (0);
}
