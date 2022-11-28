/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:10:12 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 23:17:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_t(char *n, double *p)
{
	printf("%s: %f %f %f\n", n, p[0], p[1], p[2]);
}

// orig = Ray origin
// center = Sphere center
// factor is used for optimization
// return nothing
void	intersect_s(t_elem *elem, t_ray *ray, t_intersect_list *i_list)
{
	double		factor;
	double		radius;
	t_tuple		s_to_ray;
	t_bhaskara	bhask;

	s_to_ray = tsub(ray -> orig, point(0, 0, 0));
	radius = elem -> diameter * 0.5;
	bhask.a = tdot(ray -> dir, ray -> dir);
	bhask.b = 2 * tdot(ray -> dir, s_to_ray);
	bhask.c = tdot(s_to_ray, s_to_ray) - 1;
	bhask.discri = (bhask.b * bhask.b) - (4 * bhask.a * bhask.c);
	if (bhask.discri < 0)
		return ;
	factor = 1.0 / (2.0 * bhask.a);
	if (bhask.discri > 0)
	{
		add_intersect(i_list, elem, (- bhask.b + sqrt(bhask.discri)) * factor);
		add_intersect(i_list, elem, (- bhask.b - sqrt(bhask.discri)) * factor);
	}
	else
		add_intersect(i_list, elem, (- bhask.b + sqrt(bhask.discri)) * factor);
}
