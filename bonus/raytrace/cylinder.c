/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:28:31 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/02 21:33:29 by ensebast         ###   ########.br       */
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

	x = ray->orig.tup[0] + (t * ray->dir.tup[0]);
	z = ray->orig.tup[2] + (t * ray->dir.tup[2]);
	return ((x * x) + (z * z) <= 1);
}

static void	intersect_caps(t_elem *elem, t_ray *ray, t_intersect_list *i_list)
{
	double	t[2];
	double	factor;

	if (fabs(ray->dir.tup[1]) < EPSILON)
		return ;
	factor = 1 / ray->dir.tup[1];
	t[0] = (elem->min - ray->orig.tup[1]) * factor;
	t[1] = (elem->max - ray->orig.tup[1]) * factor;
	if (check_cap(ray, t[0]))
		add_intersect(i_list, elem, t[0]);
	if (check_cap(ray, t[1]))
		add_intersect(i_list, elem, t[1]);
}

static int	bhaskara_solve(t_bhaskara *bhask, t_ray *ray)
{
	bhask->a = (ray->dir.tup[0] * ray->dir.tup[0])
		+ (ray->dir.tup[2] * ray->dir.tup[2]);
	if (fabs(bhask->a) < EPSILON)
		return (0);
	bhask->b = 2 * (ray->orig.tup[0] * ray->dir.tup[0]
			+ ray->orig.tup[2] * ray->dir.tup[2]);
	bhask->c = (ray->orig.tup[0] * ray->orig.tup[0])
		+ (ray->orig.tup[2] * ray->orig.tup[2]) - 1;
	bhask->discri = (bhask->b * bhask->b) - (4 * bhask->a * bhask->c);
	if (bhask->discri < 0)
		return (0);
	return (1);
}

void	intersect_cy(t_elem *elem, t_ray *ray, t_intersect_list *i_list)
{
	double		t[2];
	double		y[2];
	double		factor;
	t_bhaskara	bhask;

	intersect_caps(elem, ray, i_list);
	if (bhaskara_solve(&bhask, ray))
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
