/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:35 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/27 16:12:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1- Success | 0- fail

int	check_light(char *line)
{
	if (check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 3, check_int)
		&& check_segment(line, 0, 3, check_int_len)
		&& check_and_move(&line, 0, 0) == -1)
		return (1);
	return (0);
}

int	check_camera(char *line)
{
	if (check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 3, check_float)
		&& check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 0, 0) == -1)
		return (1);
	return (0);
}

int	check_ambient_light(char *line)
{
	if (check_and_move(&line, 1, check_float)
		&& check_and_move(&line, 3, check_int)
		&& check_segment(line, 0, 3, check_int_len)
		&& check_and_move(&line, 0, 0) == -1)
		return (1);
	return (0);
}
