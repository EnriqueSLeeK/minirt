/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:37:47 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 01:04:59 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_computation	prepare_computation(t_intersect *inter, t_ray *ray)
{
	t_computation	comp;

	comp.elem = inter -> elem;
	comp.t = inter -> t;
	comp.position = position(ray, comp.t);
	if (ft_strncmp(inter -> elem -> type, "pl", 2) == 0)
		comp.normalv = inter -> elem -> norm_vec;
	else
		comp.normalv = normal_at(comp.elem, comp.position);
	comp.eyev = tneg(ray -> dir);
	comp.over_point = tadd(comp.position, tsmult(comp.normalv, EPSILON));
	comp.inside = 0;
	if (tdot(comp.normalv, comp.eyev) < 0)
	{
		comp.inside = 1;
		comp.normalv = tneg(comp.normalv);
	}
	return (comp);
}
