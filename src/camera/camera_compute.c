/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_compute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:51:57 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 18:31:12 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_compute(t_camera *camera, double h_size, double v_size)
{
	double	half_view;
	double	aspect;

	half_view = tan(camera -> fov / 2.0);
	aspect = h_size / v_size;
	if (aspect >= 1.0)
	{
		camera -> half_width = half_view;
		camera -> half_height = half_view / aspect;
	}
	else
	{
		camera -> half_width = half_view * aspect;
		camera -> half_height = half_view;
	}
	camera -> pixel_size = (camera -> half_width * 2.0) / h_size;
}

t_tuple	get_up(t_tuple orientation)
{
	t_tuple	up;

	if (cmp_float(1, fabs(orientation.tup[1])))
		return (vector(1, 0, 0));
	up = tcross(vector(0, 1, 0), orientation);
	up = tcross(orientation, up);
	return (up);
}
