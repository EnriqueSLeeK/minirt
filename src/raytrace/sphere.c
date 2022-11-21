/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:10:12 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 01:51:35 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// orig = Ray origin
// center = Sphere center
// factor is used for optimization
// return nothing
void	intersect_s(t_elem *elem, t_ray *ray, t_intersect_list *i_list)
{
	double		*s_to_ray;
	double		factor;
	t_bhaskara	bhask;

	s_to_ray = tsub(ray -> orig, elem -> coord);
	bhask.a = tdot(ray -> dir, ray -> dir);
	bhask.b = 2 * tdot(ray -> dir, s_to_ray);
	bhask.c = tdot(s_to_ray, s_to_ray)
		- (elem -> diameter * elem -> diameter * 0.25);
	free(s_to_ray);
	bhask.discri = bhask.b * bhask.b - 4 * bhask.a * bhask.c;
	if (bhask.discri < 0)
		return ;
	factor = 1.0 / (2.0 * bhask.a);
	if (!cmp_float(bhask.discri, 0))
	{
		add_intersect(i_list, elem, (- bhask.b + sqrt(bhask.discri)) * factor);
		add_intersect(i_list, elem, (- bhask.b - sqrt(bhask.discri)) * factor);
	}
	else
		add_intersect(i_list, elem, (- bhask.b + sqrt(bhask.discri)) * factor);
}

double	*normal_at_s(t_elem *elem, double *p)
{
	double	*diff;
	double	*norm;

	diff = tsub(elem -> coord, p);
	norm = tnorm(diff);
	free(diff);
	return (norm);
}
