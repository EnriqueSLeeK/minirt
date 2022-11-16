/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:04:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/10/24 13:54:18 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 - Success
// 0 - Failure
static int	cmp_name(char *line, char *name)
{
	while (*name && *line && *line != ' ')
	{
		if (*name != *line)
			return (0);
		line++;
		name++;
	}
	return (1);
}

static int	set_name(char *buff, char *name)
{
	while (*name)
	{
		*buff = *name;
		name++;
		buff++;
	}
	*buff = 0;
	return (1);
}

int	matrix_fourth(double *coord, double *vec)
{
	if (coord)
		coord[3] = 1.0;
	if (vec)
		vec[3] = 0.0;
	return (1);
}

/*
 * Return values
 * 0 - failure
 * 1 - success
 */
int	parse_line(char *line, t_list_elem *elem)
{
	if (cmp_name(line, "A"))
		return (parse_ambient_light(line, elem -> ambient));
	if (cmp_name(line, "C")
			&& matrix_fourth(elem -> camera -> coord, elem -> camera -> norm_vec))
		return (parse_camera(line, elem -> camera));
	if (cmp_name(line, "L")
			&& matrix_fourth(elem -> light -> coord, NULL))
		return (parse_light(line, elem -> light));
	if (cmp_name(line, "sp")
			&& matrix_fourth(elem -> elem -> coord, elem -> elem -> norm_vec)
			&& set_name(elem -> elem -> type, "sp"))
		return (parse_sphere(line, elem -> elem));
	if (cmp_name(line, "pl")
			&& matrix_fourth(elem -> elem -> coord, elem -> elem -> norm_vec)
			&& set_name(elem -> elem -> type, "pl"))
		return (parse_plane(line, elem -> elem));
	if (cmp_name(line, "cy")
			&& matrix_fourth(elem -> elem -> coord, elem -> elem -> norm_vec)
			&& set_name(elem -> elem -> type, "cy"))
		return (parse_cylinder(line, elem -> elem));
	return (0);
}
