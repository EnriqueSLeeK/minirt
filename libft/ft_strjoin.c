/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

void	ft_copy(char const *s, char *target, int *pivot_res)
{
	int	pivot;

	pivot = 0;
	while (s[pivot])
	{
		target[*pivot_res] = s[pivot];
		pivot += 1;
		*pivot_res += 1;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		max_size;
	int		pivot_res;

	pivot_res = 0;
	max_size = ft_get_size(s1) + ft_get_size(s2);
	result = (char *) malloc (max_size + 1);
	if (result == NULL)
		return (NULL);
	ft_copy(s1, result, &pivot_res);
	ft_copy(s2, result, &pivot_res);
	result[pivot_res] = 0;
	return (result);
}
