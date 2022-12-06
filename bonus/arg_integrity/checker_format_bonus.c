/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_format_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/04 22:18:01 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	check_sphere(char *line)
{
	if (check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 3, check_int)
		&& check_segment(line, 0, 3, check_int_len))
	{
		if (check_and_move(&line, 0, NULL) == -1
			|| check_pattern_mode(&line))
			return (1);
	}
	return (0);
}

int	check_plane(char *line)
{
	if (check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 3, check_int)
		&& check_segment(line, 0, 3, check_int_len))
	{
		if (check_and_move(&line, 0, NULL) == -1
			|| check_pattern_mode(&line))
			return (1);
	}
	return (0);
}

int	check_cylinder(char *line)
{
	if (check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 3, check_int)
		&& check_segment(line, 0, 3, check_int_len))
	{
		if (check_and_move(&line, 0, NULL) == -1
			|| check_pattern_mode(&line))
			return (1);
	}
	return (0);
}

int	check_cone(char *line)
{
	if (check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 3, check_int)
		&& check_segment(line, 0, 3, check_int_len))
	{
		if (check_and_move(&line, 0, NULL) == -1
			|| check_pattern_mode(&line))
			return (1);
	}
	return (0);
}
