/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:15 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/12 00:06:37 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	delim_count(char const *s, char c)
{
	int	amount;
	int	index;
	int	flag;

	flag = 1;
	index = 0;
	amount = 0;
	if (s[0] == 0)
		return (1);
	if (s[0] != c)
		amount += 1;
	while (s[index])
	{
		if (s[index] == c && flag)
		{
			amount += 1;
			flag = 0;
		}
		if (s[index] != c && !(flag))
			flag = 1;
		index += 1;
	}
	if (flag)
		amount += 1;
	return (amount);
}

static char	*populate(char const *relative_s, char c, int size)
{
	char	*str;
	int		i;

	if (size <= 0)
		return (0);
	i = 0;
	str = ft_calloc(1, size + 1);
	while (relative_s[i] != c && relative_s[i] != '\0')
	{
		str[i] = relative_s[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

static void	check_assign(char **alloc_str, int *m_i, char *str)
{
	if (str && str[0] != 0)
	{
		*m_i += 1;
		alloc_str[*m_i] = str;
	}
}

static void	init(int *start, int *m_i, int *i)
{
	*start = 0;
	*m_i = -1;
	*i = 0;
}

char	**ft_split(char const *s, char c)
{	
	char	**result;
	int		start;
	int		end;
	int		m_i;
	int		i;

	result = ft_calloc ((delim_count(s, c)), sizeof(char *));
	if (result == 0)
		return (0);
	init(&start, &m_i, &i);
	while (s[i])
	{
		if (s[i] == c)
		{
			end = i;
			check_assign(result, &m_i, populate(&s[start], c, end - start));
			start = i + 1;
		}
		i += 1;
	}
	end = i;
	if (s[i] == 0)
		check_assign(result, &m_i, populate(&s[start], c, end - start));
	return (result);
}
