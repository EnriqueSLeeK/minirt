/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:09:17 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/24 23:12:27 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1- Success | 0- fail
int	check_int_len(char *num)
{
	int	len;

	len = ft_strlen(num);
	if (len > 10)
		return (0);
	return (1);
}

// 1- Success | 0- fail
int	check_int(char *segment)
{
	if (match_exp("*", segment)
		|| match_exp("-*", segment))
		return (1);
	return (0);
}

// 1- Success | 0- fail
int	check_float(char *segment)
{
	if (match_exp("*.*", segment)
		|| match_exp("-*.*", segment)
		|| check_int(segment))
		return (1);
	return (0);
}

// 1- Success | 0- fail
int	check_segment(char *segment, int cycle, int limit,
					int (*checker)(char *))
{
	int		ref;
	char	tmp;

	if (cycle == limit)
		return (1);
	if (cycle < limit - 1)
		ref = find_char(segment, ',');
	else
		ref = find_char(segment, ' ');
	if (segment[ref] == 0)
	{
		if (cycle == (limit - 1) && checker(segment))
			return (1);
		return (0);
	}
	tmp = segment[ref];
	segment[ref] = 0;
	if (checker(segment))
	{
		segment[ref] = tmp;
		return (check_segment(segment + (ref + 1),
				cycle + 1, limit, checker));
	}
	return (0);
}

/* -1 -> End of line
*   1 -> Success
*   0 -> Fail
*/
int	check_and_move(char **line, int nelem, int (*check)(char *))
{
	int	offset;

	offset = next_segment(*line);
	if (offset > -1)
	{
		*line += offset;
		if (**line == 0)
			return (-1);
		if (check != 0 && check_segment(*line, 0, nelem, check))
			return (1);
	}
	return (0);
}
