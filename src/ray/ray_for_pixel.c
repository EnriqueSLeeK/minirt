/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:05:58 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 17:39:01 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_for_pixel(t_camera *camera, double px, double py)
{
	double		offset[2];
	double		world_coord[2];
	t_matrix	inv_transform;
	t_tuple		pixel;
	t_ray		ray;

	inv_transform = inverse_m(camera -> transform);
	offset[0] = (px + 0.5) * camera -> pixel_size;
	offset[1] = (py + 0.5) * camera -> pixel_size;
	world_coord[0] = camera -> half_width - offset[0];
	world_coord[1] = camera -> half_height - offset[1];
	pixel = point(world_coord[0], world_coord[1], -1);
	pixel = m_mult_t(inv_transform, pixel);
	ray.orig = m_mult_t(inv_transform, point(0, 0, 0));
	ray.dir = tnorm(tsub(pixel, ray.orig));
	return (ray);
}
