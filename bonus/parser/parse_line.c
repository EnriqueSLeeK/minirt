/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:04:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/02 20:59:04 by ensebast         ###   ########.br       */
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

/*
 * Return values
 * 0 - failure
 * 1 - success
 */
int	parse_line(char *line, t_list_elem *elem)
{
	if (cmp_name(line, "A"))
		return (parse_ambient_light(line, elem -> ambient));
	if (cmp_name(line, "C"))
		return (parse_camera(line, elem -> camera));
	if (cmp_name(line, "L"))
		return (parse_light(line, &elem -> light));
	if (cmp_name(line, "sp"))
		return (parse_sphere(line, &elem -> elem));
	if (cmp_name(line, "pl"))
		return (parse_plane(line, &elem -> elem));
	if (cmp_name(line, "cy"))
		return (parse_cylinder(line, &elem -> elem));
	return (0);
}
