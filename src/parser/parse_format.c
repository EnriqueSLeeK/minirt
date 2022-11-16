/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/24 22:21:56 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 - Success | 0 - Failure
int	parse_sphere(char *line, t_elem *elem)
{
	if (parse_and_move(&line, 3, elem -> coord, parse_float)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 3, elem -> color, parse_color)
		&& range_double_check(elem -> color, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
		return (1);
	elem += 1;
	return (0);
}

int	parse_plane(char *line, t_elem *elem)
{
	if (parse_and_move(&line, 3, elem -> coord, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec, parse_float)
		&& range_double_check(elem -> norm_vec, 3, -1.0, 1.0)
		&& parse_and_move(&line, 3, elem -> color, parse_color)
		&& range_double_check(elem -> color, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
		return (1);
	elem += 1;
	return (0);
}

int	parse_cylinder(char *line, t_elem *elem)
{
	if (parse_and_move(&line, 3, elem -> coord, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec, parse_float)
		&& range_double_check(elem -> norm_vec, 3, -1.0, 1.0)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 1, &(elem -> height), parse_float)
		&& parse_and_move(&line, 3, elem -> color, parse_int)
		&& range_double_check(elem -> color, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
		return (1);
	elem += 1;
	return (0);
}
