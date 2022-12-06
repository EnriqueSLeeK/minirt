/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:37:47 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 23:19:46 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_computation	prepare_computation(t_intersect *inter, t_ray *ray)
{
	t_computation	comp;

	comp.elem = inter -> elem;
	comp.t = inter -> t;
	comp.position = position(ray, comp.t);
	comp.normalv = normal_at(comp.elem, comp.position);
	comp.eyev = tneg(ray -> dir);
	if (tdot(comp.normalv, comp.eyev) < 0)
		comp.normalv = tneg(comp.normalv);
	comp.over_point = tadd(comp.position, tsmult(comp.normalv, EPSILON));
	return (comp);
}
