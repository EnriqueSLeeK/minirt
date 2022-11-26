/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:10:12 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 00:00:52 by ensebast         ###   ########.br       */
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

	s_to_ray = tsub(&ray -> orig, &elem -> coord);
	radius = elem -> diameter * 0.5;
	bhask.a = tdot(&ray -> dir, &ray -> dir);
	bhask.b = 2 * tdot(&ray -> dir, &s_to_ray);
	bhask.c = tdot(&s_to_ray, &s_to_ray) - (radius * radius);
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

t_tuple	normal_at_s(t_elem *elem, t_tuple *w_p)
{
	t_matrix	inv_matrix;
	t_tuple		world_normal;
	t_tuple		obj_normal;
	t_tuple		obj_point;

	inv_matrix = inverse_m(&elem -> transform);
	obj_point = m_mult_t(&inv_matrix, w_p);
	obj_normal = create_t(0, 0, 0, 1);
	obj_normal = tsub(&obj_point, &obj_normal);
	transpose_m(&inv_matrix);
	world_normal = m_mult_t(&inv_matrix, &obj_normal);
	world_normal.tup[3] = 0;
	return (tnorm(&world_normal));
}
