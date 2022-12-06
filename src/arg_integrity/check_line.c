/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:04:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 17:35:58 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 - Success
// 0 - Failure
static int	cmp_name(char *line, char *name, int *count)
{
	while (*name && *line && *line != ' ')
	{
		if (*name != *line)
			return (0);
		line++;
		name++;
	}
	*count += 1;
	return (1);
}

/*
 * Return values
 * 2 - Empty line or line == null
 * 0 - failure
 * 1 - success
 */
int	check_count_line(char *line, int *count)
{
	if (line == 0
		|| *line == 0
		|| *line == '\n')
		return (2);
	if (cmp_name(line, "A", &(count[2])))
		return (check_ambient_light(line));
	if (cmp_name(line, "C", &(count[3])))
		return (check_camera(line));
	if (cmp_name(line, "L", &(count[1])))
		return (check_light(line));
	if (cmp_name(line, "sp", &(count[0])))
		return (check_sphere(line));
	if (cmp_name(line, "pl", &(count[0])))
		return (check_plane(line));
	if (cmp_name(line, "cy", &(count[0])))
		return (check_cylinder(line));
	return (0);
}
