/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:34:01 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 17:55:48 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// light_component
// 0 = ambient
// 1 = diffuse
// 2 = specular
t_color	lighting(t_material *m, t_light *light,
		t_computation *info, int in_shadow)
{
	t_color	light_comp[3];
	t_color effective_c;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	dot_res;

	effective_c = cmult(*m->color, light->color);
	light_comp[0] = csmult(effective_c, m->ambient->light_ratio);
	if (in_shadow)
		return (light_comp[0]);
	lightv = tnorm(tsub(light->coord, info->position));
	dot_res = tdot(lightv, info->normalv);
	if (dot_res < 0)
		return (light_comp[0]);
	light_comp[1] = csmult(effective_c, m->diffuse * dot_res);
	reflectv = treflect(tneg(lightv), info->normalv);
	dot_res = tdot(reflectv, info->eyev);
	if (dot_res <= 0)
		return (cadd(light_comp[0], light_comp[1]));
	light_comp[2] = csmult(light->color,
			pow(dot_res, m -> shininess) * m->specular);
	light_comp[2] = cadd(light_comp[0], cadd(light_comp[1], light_comp[2]));
	return (light_comp[2]);
}
