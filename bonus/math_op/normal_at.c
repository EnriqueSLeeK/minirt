/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:16:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 15:19:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(t_elem *elem, t_tuple w_p)
{
	t_tuple		world_normal;
	t_tuple		obj_normal;
	t_tuple		obj_point;

	obj_point = m_mult_t(elem->inv_transform, w_p);
	elem -> local_normal(elem, obj_point, &obj_normal);
	world_normal = m_mult_t(elem->inv_transform_transpose, obj_normal);
	world_normal.tup[3] = 0;
	return (tnorm(world_normal));
}

void	normal_pl(t_elem *elem, t_tuple obj_p, t_tuple *tup)
{
	(void)obj_p;
	(void)elem;
	*tup = vector(0, 1, 0);
}

void	normal_sp(t_elem *elem, t_tuple obj_p, t_tuple *tup)
{
	(void)elem;
	*tup = tsub(obj_p, point(0, 0, 0));
}

void	normal_cy(t_elem *elem, t_tuple obj_p, t_tuple *tup)
{
	double	dist;

	dist = (obj_p.tup[0] * obj_p.tup[0])
		+ (obj_p.tup[2] * obj_p.tup[2]);
	if (dist < 1 && obj_p.tup[1] >= (elem -> max - EPSILON))
		*tup = vector(0, 1, 0);
	else if (dist < 1 && obj_p.tup[1] <= (elem -> min + EPSILON))
		*tup = vector(0, -1, 0);
	else
		*tup = vector(obj_p.tup[0], 0, obj_p.tup[2]);
}
