/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:35 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/04 12:58:29 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	check_normal(t_tuple t)
{
	t.tup[3] = 0;
	return (cmp_float(1, tmag(t)));
}

// 1- Success | 0- fail
int	parse_light(char *line, t_light **light)
{
	t_aux_parse	aux;

	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(aux.light_ratio), parse_float)
		&& range_double_check(&(aux.light_ratio), 1, 0.0, 1.0)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0, 1.0))
	{
		prep_light(&aux, *light);
		*light += 1;
		return (1);
	}
	return (0);
}

int	parse_camera(char *line, t_camera *elem)
{
	t_aux_parse	aux;

	if (parse_and_move(&line, 3, aux.coord.tup, parse_float)
		&& parse_and_move(&line, 3, aux.norm_vec.tup, parse_float)
		&& check_normal(aux.norm_vec)
		&& parse_and_move(&line, 1, &aux.fov, parse_float)
		&& range_double_check(&(aux.fov), 1, 0, 180)
		&& deg_to_rad(&(aux.fov)))
	{
		prep_camera(&aux, elem);
		return (1);
	}
	return (0);
}

int	parse_ambient_light(char *line, t_ambient *elem)
{
	t_aux_parse	aux;

	if (parse_and_move(&line, 1, &(aux.light_ratio), parse_float)
		&& range_double_check(&(aux.light_ratio), 1, 0.0, 1.0)
		&& parse_and_move(&line, 3, aux.color.tup, parse_color)
		&& range_double_check(aux.color.tup, 3, 0.0, 1.0))
	{
		prep_ambient(&aux, elem);
		return (1);
	}
	return (0);
}
