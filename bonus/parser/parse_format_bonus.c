/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 15:26:43 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	check_normal(t_tuple t)
{
	t.tup[3] = 0;
	return (cmp_float(1, tmag(t)));
}

// 1 - Success | 0 - Failure
int	parse_sphere(char *line, t_elem **shape, void *mlx)
{
	t_aux_parse	aux;

	aux.pattern_type = 0;
	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(aux.diameter), parse_float)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0))
	{
		parse_and_move(&line, 1, &(aux.pattern_type), set_pattern_type);
		parse_and_move(&line, 0, NULL, NULL);
		aux.filename = line;
		if (prep_sp(&aux, *shape, mlx))
		{
			*shape += 1;
			return (1);
		}
	}
	return (0);
}

int	parse_plane(char *line, t_elem **shape, void *mlx)
{
	t_aux_parse	aux;

	aux.pattern_type = 0;
	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 3, aux.norm_vec.tup, parse_float)
		&& check_normal(aux.norm_vec)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0))
	{
		parse_and_move(&line, 1, &(aux.pattern_type), set_pattern_type);
		parse_and_move(&line, 0, NULL, NULL);
		aux.filename = line;
		if (prep_pl(&aux, *shape, mlx))
		{
			*shape += 1;
			return (1);
		}
	}
	return (0);
}

int	parse_cylinder(char *line, t_elem **shape, void *mlx)
{
	t_aux_parse	aux;

	aux.pattern_type = 0;
	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 3, aux.norm_vec.tup, parse_float)
		&& check_normal(aux.norm_vec)
		&& parse_and_move(&line, 1, &(aux.diameter), parse_float)
		&& parse_and_move(&line, 1, &(aux.height), parse_float)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0))
	{
		parse_and_move(&line, 1, &(aux.pattern_type), set_pattern_type);
		parse_and_move(&line, 0, NULL, NULL);
		aux.filename = line;
		if (prep_cy(&aux, *shape, mlx))
		{
			*shape += 1;
			return (1);
		}
	}
	return (0);
}

int	parse_cone(char *line, t_elem **shape, void *mlx)
{
	t_aux_parse	aux;

	aux.pattern_type = 0;
	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 3, aux.norm_vec.tup, parse_float)
		&& check_normal(aux.norm_vec)
		&& parse_and_move(&line, 1, &(aux.diameter), parse_float)
		&& parse_and_move(&line, 1, &(aux.height), parse_float)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0))
	{
		parse_and_move(&line, 1, &(aux.pattern_type), set_pattern_type);
		parse_and_move(&line, 0, NULL, NULL);
		aux.filename = line;
		if (prep_cn(&aux, *shape, mlx))
		{
			*shape += 1;
			return (1);
		}
	}
	return (0);
}
