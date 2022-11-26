/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 22:48:23 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 - Success | 0 - Failure
int	parse_sphere(char *line, t_elem **shape)
{
	t_elem	*elem;

	elem = *shape;
	elem -> transform.size = 4;
	elem -> intersect = intersect_s;
	identity_m(&elem -> transform);
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_plane(char *line, t_elem **shape)
{
	t_elem	*elem;

	elem = *shape;
	elem -> transform.size = 4;
	identity_m(&elem -> transform);
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec.tup, parse_float)
		&& range_double_check(elem -> norm_vec.tup, 3, -1.0, 1.0)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_cylinder(char *line, t_elem **shape)
{
	t_elem	*elem;

	elem = *shape;
	elem -> transform.size = 4;
	identity_m(&elem -> transform);
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec.tup, parse_float)
		&& range_double_check(elem -> norm_vec.tup, 3, -1.0, 1.0)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 1, &(elem -> height), parse_float)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_int)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		*shape += 1;
		return (1);
	}
	return (0);
}
