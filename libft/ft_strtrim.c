/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_is_in(char const c, char const *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (c == set[k])
			return (1);
		k += 1;
	}
	return (0);
}

static char	*ft_strndup(const char *string, size_t size)
{
	char	*dup;

	if (size == 0)
	{
		dup = ft_calloc(1, 1);
		if (dup == 0)
			return (0);
		dup[0] = 0;
		return (dup);
	}
	dup = ft_calloc(1, size + 1);
	if (dup == 0)
		return (0);
	ft_strlcpy(dup, string, size + 1);
	return (dup);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	how_many_rear;
	int	len_s1;

	if (!(s1))
		return (0);
	how_many_rear = 0;
	while (ft_is_in(s1[0], set))
		s1++;
	len_s1 = ft_strlen(s1);
	if (len_s1 > 0)
		while (ft_is_in(s1[len_s1 - 1 - how_many_rear], set))
			how_many_rear++;
	return (ft_strndup(s1, ft_strlen(s1) - how_many_rear));
}
