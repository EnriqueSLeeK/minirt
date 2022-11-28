/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 00:46:59 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 - Success | 0 - Failure
int	parse_sphere(char *line, t_elem **shape)
{
	t_elem		*elem;
	double		radius;
	t_matrix	aux;

	elem = *shape;
	elem -> intersect = intersect_s;
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		elem -> transform = translation(elem -> coord.tup[0],
				elem -> coord.tup[1],
				elem -> coord.tup[2]);
		radius = elem -> diameter * 0.5;
		set_transform(elem, m_mult(elem -> transform,
					scaling(radius, radius, radius)));
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_plane(char *line, t_elem **shape)
{
	t_elem	*elem;

	elem = *shape;
	elem -> transform = create_identity_m();
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
	elem -> transform = create_identity_m();
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
