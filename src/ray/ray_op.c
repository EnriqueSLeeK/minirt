/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:06:15 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 23:09:34 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	position(t_ray *ray, double t)
{
	return (tadd(tsmult(ray -> dir, t), ray -> orig));
}

t_ray	transform_ray(t_ray *ray, t_matrix *transform)
{
	t_ray	new_ray;

	new_ray.dir = m_mult_t(*transform, ray -> dir);
	new_ray.orig = m_mult_t(*transform, ray -> orig);
	return (new_ray);
}
