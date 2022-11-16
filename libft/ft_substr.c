/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/10 22:32:54 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_start(unsigned int start, char const *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i += 1;
	if (start < i)
		return (0);
	else
		return (1);
}

size_t	get_sub_len(size_t len, size_t sub_len)
{
	if (sub_len > len)
		return (len);
	else
		return (sub_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p_char;
	size_t	index;

	if (check_start(start, s))
	{
		p_char = (char *) ft_calloc (1, 1);
		return (p_char);
	}
	p_char = (char *) ft_calloc (1, get_sub_len(len, ft_strlen(&s[start])) + 1);
	if (p_char == 0)
		return (0);
	index = 0;
	while (index < len && s[start])
	{
		p_char[index] = s[start];
		index += 1;
		start += 1;
	}
	p_char[index] = '\0';
	return (p_char);
}
