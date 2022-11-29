/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 20:55:50 by ensebast         ###   ########.br       */
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
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		elem -> intersect = intersect_s;
		elem -> local_normal = normal_sp;
		aux = translation(elem -> coord.tup[0],
				elem -> coord.tup[1],
				elem -> coord.tup[2]);
		radius = elem -> diameter * 0.5;
		aux = m_mult(aux, scaling(radius, radius, radius));
		set_transform(elem, aux);
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_plane(char *line, t_elem **shape)
{
	t_elem		*elem;
	t_matrix	aux;

	elem = *shape;
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec.tup, parse_float)
		&& range_double_check(elem -> norm_vec.tup, 3, -1.0, 1.0)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		elem -> intersect = intersect_pl;
		elem -> local_normal = normal_pl;
		aux = translation(elem -> coord.tup[0],
				elem -> coord.tup[1],
				elem -> coord.tup[2]);
		set_transform(elem, aux);
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_cylinder(char *line, t_elem **shape)
{
	t_elem		*elem;
	t_matrix	aux;
	double		radius;

	elem = *shape;
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec.tup, parse_float)
		&& range_double_check(elem -> norm_vec.tup, 3, -1.0, 1.0)
		&& parse_and_move(&line, 1, &(elem -> diameter), parse_float)
		&& parse_and_move(&line, 1, &(elem -> height), parse_float)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		aux = translation(elem->coord.tup[0],
				elem->coord.tup[1],
				elem->coord.tup[2]);
		radius = elem -> diameter * 0.5;
		aux = m_mult(aux, scaling(radius, 1, radius));
		set_transform(elem, aux);
		elem -> max = elem -> height / 2;
		elem -> min = -elem -> max;
		elem -> intersect = intersect_cy;
		elem -> local_normal = normal_cy;
		*shape += 1;
		return (1);
	}
	return (0);
}
