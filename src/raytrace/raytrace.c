/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:58:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 23:59:58 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	raytrace(t_list_elem *list_elem)
{
	/*
	t_ray	ray;
	ray.dir = create_t(0, 0, 1, 0);
	ray.orig = create_t(0, 0, -5, 1);
	set_transform(&list_elem -> elem[0], scaling(0.5, 0.5, 0.5));
	t_matrix ident = create_m(4);
	identity_m(&ident);
	set_transform(&list_elem -> elem[1], ident);
	ray_shoot(list_elem, &ray);
	*/
	start_raytrace(list_elem);
}

// Multiple source of light support
static int	shade_hit(t_list_elem *list_elem, t_computation *comp)
{
	int		i;
	t_color	buff;
	t_color	color;

	i = -1;
	color = create_c(0, 0, 0);
	while (++i < list_elem -> quant[1])
	{
		buff = lighting(&comp->elem->material, &list_elem -> light[i], comp);
		color = cadd(&color, &buff);
	}
	return (make_color(color.tup[0], color.tup[1], color.tup[2]));
}

// If hit_elem != NULL then draw
// Else put a black pixel
static void	coloring(t_list_elem *list_elem, t_ray *ray, t_intersect *hit_elem, double *coord)
{
	t_computation	comp;

	if (hit_elem)
	{
		comp = prepare_computation(hit_elem, ray);
		put_pixel(&list_elem -> mlx_inf.img_inf, coord[0],
				coord[1], shade_hit(list_elem, &comp));
	}
	else
		put_pixel(&list_elem -> mlx_inf.img_inf, coord[0], coord[1], 0);
}

/*
 * coord [0] = x
 * coord [1] = y
 */
void	start_raytrace(t_list_elem *list_elem)
{
	t_ray		ray;
	double		coord[2];
	t_intersect	*hit_elem;

	coord[0] = -1;
	coord[1] = -1;
	ray.orig = list_elem -> camera -> coord;
	while (coord[0]++ < HEIGHT)
	{
		while (coord[1]++ < WIDTH)
		{
			ray.dir = create_t(((coord[0] / WIDTH) * 2) - 1,
					((coord[1] / HEIGHT) * 2) - 1, 1, 0);
			ray.dir = tnorm(&ray.dir);
			hit_elem = ray_shoot(list_elem, &ray);
			coloring(list_elem, &ray, hit_elem, coord);
		}
		coord[1] = 0;
	}
}

t_intersect	*ray_shoot(t_list_elem *list_elem, t_ray *ray)
{
	int			i;
	t_elem		*elem;
	t_ray		obj_ray;

	i = 0;
	elem = list_elem -> elem;
	while (i < list_elem -> quant[0])
	{
		obj_ray = ray_to_object_space(ray, &list_elem -> elem[i].transform);
		elem[i].intersect(&elem[i], &obj_ray, list_elem -> intersect_l);
		i++;
	}
	return (hit(list_elem -> intersect_l));
}

t_intersect	*hit(t_intersect_list *list)
{
	int			i;
	double		min;
	double		t_value;
	t_intersect	*resp;

	i = 0;
	resp = NULL;
	min = INFINITY;
	while (i < list -> n)
	{
		t_value = list -> elem_inter[i].t;
		if (t_value > 0 && t_value < min)
		{
			min = t_value;
			resp = &list -> elem_inter[i];
		}
		i++;
	}
	list -> n = 0;
	return (resp);
}
