/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:46:35 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 18:56:19 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	verify_shadow(t_list_elem *list_elem, t_ray *ray, double dist)
{
	t_intersect	*hit_obj;

	hit_obj = ray_shoot(list_elem, ray);
	return (hit_obj && hit_obj->t < dist);
}

int	is_shadowed(t_list_elem *list_elem, t_tuple point, int i)
{
	t_tuple	vector;
	t_tuple	direction;
	double	distance;
	t_ray	ray;

	vector = tsub(list_elem->light[i].coord, point);
	direction = tnorm(vector);
	distance = tmag(vector);
	ray.dir = direction;
	ray.orig = point;
	if (verify_shadow(list_elem, &ray, distance))
		return (1);
	return (0);
}
