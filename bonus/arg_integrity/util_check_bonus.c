/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:40:43 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 20:31:07 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	find_char(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	return (i);
}

// Search next segment
int	next_segment(char *line)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (line[i])
	{
		if (flag == 0 && line[i] == ' ')
			flag = 1;
		if (flag && line[i] != ' ')
			break ;
		i++;
	}
	if (!(line[i]) && flag)
		return (-1);
	return (i);
}
