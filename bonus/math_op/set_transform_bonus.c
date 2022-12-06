/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:00:06 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 20:31:07 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

// Pre calculate inverse because is used a lot of times

void	set_transform(t_elem *elem, t_matrix transform)
{
	elem -> transform = transform;
	elem -> inv_transform = inverse_m(elem -> transform);
	elem -> inv_transform_transpose = transpose_m(elem -> inv_transform);
}

void	set_camera_transform(t_camera *camera, t_matrix transform)
{
	camera -> transform = transform;
	camera -> inv_transform = inverse_m(camera -> transform);
}
