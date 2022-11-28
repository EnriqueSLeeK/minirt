/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:16:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 16:47:31 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(t_elem *elem, t_tuple w_p)
{
	t_tuple		world_normal;
	t_tuple		obj_normal;
	t_tuple		obj_point;

	obj_point = m_mult_t(elem->inv_transform, w_p);
	obj_normal = elem -> local_normal(obj_point);
	world_normal = m_mult_t(elem->inv_transform_transpose, obj_normal);
	world_normal.tup[3] = 0;
	return (tnorm(world_normal));
}

t_tuple	normal_pl(t_tuple obj_p)
{
	(void)obj_p;
	return (vector(0, 1, 0));
}

t_tuple	normal_sp(t_tuple obj_p)
{
	return (tsub(obj_p, point(0, 0, 0)));
}
