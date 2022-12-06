/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:34:01 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 15:18:44 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_color	calc_diffuse(t_color eff_c, double mat_diff, double light_dot)
{
	t_color	diff;

	if (light_dot < 0)
		return (create_c(0, 0, 0));
	diff = csmult(eff_c, mat_diff * light_dot);
	return (diff);
}

t_color	calc_specular(t_color light_intensity, double mat_specular,
		double shininess, double ref_dot_eye)
{
	t_color	specular;
	double	factor;

	if (ref_dot_eye <= 0)
		return (create_c(0, 0, 0));
	factor = pow(ref_dot_eye, shininess);
	specular = csmult(light_intensity, mat_specular * factor);
	return (specular);
}

double	reflection(t_tuple lightv, t_tuple normalv, t_tuple eyev)
{
	t_tuple	reflectv;

	reflectv = treflect(tneg(lightv), normalv);
	return (tdot(reflectv, eyev));
}

// light_component
// 0 = ambient
// 1 = diffuse
// 2 = specular
t_color	lighting(t_material *m, t_light *light,
		t_computation *info, int in_shadow)
{
	t_color	eff_c;
	t_color	final_color;
	t_tuple	lightv;
	double	light_dot;
	double	ref_dot_eye;

	eff_c = cmult(m->color, light->color);
	final_color = cmult(eff_c, m->ambient);
	if (in_shadow)
		return (final_color);
	lightv = tnorm(tsub(light->coord, info->over_point));
	light_dot = tdot(lightv, info->normalv);
	final_color = cadd(final_color, calc_diffuse(eff_c,
				m->diffuse, light_dot));
	ref_dot_eye = reflection(lightv, info->normalv, info->eyev);
	final_color = cadd(final_color, calc_specular(light->color,
				m->specular, m->shininess, ref_dot_eye));
	return (final_color);
}
