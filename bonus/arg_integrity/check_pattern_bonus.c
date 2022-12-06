/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pattern_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:46:19 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/04 22:25:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	check_pattern_mode(char **line)
{
	int		offset;
	char	*buff;

	buff = *line;
	if (ft_strncmp(*line, "checker_pattern", 16) == 0
		&& check_and_move(line, 0, NULL) == -1)
		return (1);
	*line = buff;
	if (ft_strncmp(*line, "bumpmap_pattern", 16) == ' ')
	{
		offset = next_segment(*line);
		*line += offset;
		if (extension_check(*line, "xpm") == 0
			&& check_and_move(line, 0, NULL) == -1)
			return (1);
	}
	return (0);
}
