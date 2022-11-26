/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_compute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:51:57 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 22:56:35 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_compute(t_camera *camera)
{
	double	half_view;
	double	aspect;

	half_view = tan(camera -> fov * 0.5);
	aspect = HEIGHT / WIDTH;
	if (aspect >= 1)
	{
		camera -> half_width = half_view;
		camera -> half_height = half_view / aspect;
	}
	else
	{
		camera -> half_width = half_view * aspect;
		camera -> half_height = half_view;
	}
	camera -> pixel_size = (camera -> half_width * 2) / camera -> half_width;
}
