/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:53:35 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 16:29:34 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// 1- Success | 0- fail
int	parse_light(char *line, t_light **light)
{
	t_light	*elem;

	elem = *light;
	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 1, &(elem -> light_ratio), parse_float)
		&& range_double_check(&(elem -> light_ratio), 1, 0.0, 1.0)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0, 1.0))
	{
		*light += 1;
		return (1);
	}
	return (0);
}

int	parse_camera(char *line, t_camera *elem)
{
	t_tuple	up;

	if (parse_and_move(&line, 3, elem -> coord.tup, parse_float)
		&& parse_and_move(&line, 3, elem -> norm_vec.tup, parse_float)
		&& range_double_check(elem -> norm_vec.tup, 3, -1.0, 1.0)
		&& parse_and_move(&line, 1, &elem -> fov, parse_float)
		&& range_double_check(&(elem -> fov), 1, 0, 180)
		&& deg_to_rad(&(elem -> fov)))
	{
		camera_compute(elem, WIDTH, HEIGHT);
		up = get_up(elem -> norm_vec);
		double *t = up.tup;
		set_camera_transform(elem,
				view_transform(elem->coord, elem -> norm_vec, up));
		return (1);
	}
	return (0);
}

int	parse_ambient_light(char *line, t_ambient *elem)
{
	if (parse_and_move(&line, 1, &(elem -> light_ratio), parse_float)
		&& range_double_check(&(elem -> light_ratio), 1, 0.0, 1.0)
		&& parse_and_move(&line, 3, elem -> color.tup, parse_color)
		&& range_double_check(elem -> color.tup, 3, 0.0, 1.0))
		return (1);
	return (0);
}
