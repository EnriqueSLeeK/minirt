/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/04 12:57:27 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_normal(t_tuple t)
{
	t.tup[3] = 0;
	return (cmp_float(tmag(t), 1));
}

// 1 - Success | 0 - Failure
int	parse_sphere(char *line, t_elem **shape)
{
	t_aux_parse	aux;

	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(aux.diameter), parse_float)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		prep_sp(&aux, *shape);
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_plane(char *line, t_elem **shape)
{
	t_aux_parse	aux;

	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 3, aux.norm_vec.tup, parse_float)
		&& check_normal(aux.norm_vec)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		prep_pl(&aux, *shape);
		*shape += 1;
		return (1);
	}
	return (0);
}

int	parse_cylinder(char *line, t_elem **shape)
{
	t_aux_parse	aux;

	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 3, aux.norm_vec.tup, parse_float)
		&& check_normal(aux.norm_vec)
		&& parse_and_move(&line, 1, &(aux.diameter), parse_float)
		&& parse_and_move(&line, 1, &(aux.height), parse_float)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0)
		&& parse_and_move(&line, 0, 0, NULL) == -1)
	{
		prep_cy(&aux, *shape);
		*shape += 1;
		return (1);
	}
	return (0);
}
