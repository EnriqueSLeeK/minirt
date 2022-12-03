/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:46:28 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 15:08:17 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	prep_camera(t_aux_parse *info, t_camera *elem)
{
	t_tuple	up;

	info->coord.tup[3] = 1;
	info->norm_vec.tup[3] = 0;
	camera_compute(elem, info->fov, WIDTH, HEIGHT);
	up = get_up(info->norm_vec);
	set_camera_transform(elem,
		view_transform(info->coord, info->norm_vec, up));
}

void	prep_light(t_aux_parse *info, t_light *elem)
{
	info->coord.tup[3] = 1;
	elem->coord = info->coord;
	elem->light_ratio = info->light_ratio;
	elem->color = csmult(info->color, info->light_ratio);
}

void	prep_ambient(t_aux_parse *info, t_ambient *elem)
{
	elem->color = csmult(info->color, info->light_ratio);
}
