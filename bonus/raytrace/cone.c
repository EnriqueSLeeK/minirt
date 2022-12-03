/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:09:20 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/02 17:55:31 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_y(double y, t_elem *elem)
{
	if (y > elem -> min && y < elem -> max)
		return (1);
	return (0);
}

static int	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->orig.tup[0] + t * ray->dir.tup[0];
	z = ray->orig.tup[2] + t * ray->dir.tup[2];
	return ((x * x) + (z * z) <= 1);
}

static int	bhaskara_solver(t_bhaskara *bhask, t_ray *ray)
{
	bhask->a = ray->dir.tup[0] * ray->dir.tup[0]
		+ ray->dir.tup[1] * ray->dir.tup[1]
		+ ray->dir.tup[2] * ray->dir.tup[2];
	bhask->b = 2 * ray->orig.tup[0] * ray->dir.tup[0]
		- 2 * ray->orig.tup[1] * ray->dir.tup[1]
		+ 2 * ray->orig.tup[2] * ray->dir.tup[2];
	bhask->c = ray->orig.tup[0] * ray->orig.tup[0]
		+ ray->orig.tup[1] * ray->orig.tup[1]
		+ ray->orig.tup[2] * ray->orig.tup[2];
	bhask->discri = (bhask->b * bhask->b)
		- 4 * bhask->a * bhask->c;
	if (bhask->discri < 0)
		return (0);
	return (1);
}

void	intersect_cone(t_elem *elem, t_ray *ray, t_intersect_list *i_list)
{
	double		t[2];
	double		y[2];
	double		factor;
	t_bhaskara	bhask;

	if (bhaskara_solver(&bhask, ray))
	{
		if (fabs(bhask.a) < EPSILON && !float_cmp(0, bhask.b))
			add_intersect(i_list, elem, -bhask.c / (2 * bhask.b));
		else
		{
			factor = 1.0 / (2.0 * bhask.a);
			t[0] = (-bhask.b + sqrt(bhask.discri)) * factor;
			t[1] = (-bhask.b - sqrt(bhask.discri)) * factor;
			y[0] = ray->orig.tup[1] + (ray->dir.tup[1] * t[0]);
			y[1] = ray->orig.tup[1] + (ray->dir.tup[1] * t[1]);
			if (check_y(y[0], elem))
				add_intersect(i_list, elem, t[0]);
			if (!cmp_float(t[1], t[0]) && check_y(y[1], elem))
				add_intersect(i_list, elem, t[1]);
		}
	}
}
