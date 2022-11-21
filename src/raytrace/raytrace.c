/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:58:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 23:00:28 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Prepare mlx and start raytracing
void	raytrace(t_list_elem *list_elem)
{
	start_raytrace(list_elem);
	printf("Elem:    %d\n", list_elem -> quant[0]);
	printf("Light:   %d\n", list_elem -> quant[1]);
	printf("Ambient: %d\n", list_elem -> quant[2]);
	printf("Camera:  %d\n", list_elem -> quant[3]);
}

/*
 * coord [0] = x
 * coord [1] = y
 */
void	start_raytrace(t_list_elem *list_elem)
{
	t_ray	ray;
	double	coord[2];
	t_elem	*hit_elem;

	coord[0] = 0;
	coord[1] = 0;
	ray.orig = list_elem -> camera -> coord;
	while (coord[0] < HEIGHT)
	{
		while (coord[1] < WIDTH)
		{
			ray.dir = vec_init(((coord[0] / WIDTH) * 2) - 1, ((coord[1] / HEIGHT) * 2) - 1, 1, 0);
			hit_elem = ray_shoot(list_elem, &ray);
			if (hit_elem)
				put_pixel(list_elem -> mlx_inf.img, coord[0], coord[1],
						make_color(hit_elem -> color[0], hit_elem -> color[1],
						hit_elem -> color[2]));
			else
				put_pixel(list_elem -> mlx_inf.img, coord[0], coord[1], 0);
			free(ray.dir);
			coord[1]++;
		}
		coord[1] = 0;
		coord[0]++;
	}
}

t_elem	*ray_shoot(t_list_elem *list_elem, t_ray *ray)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = list_elem -> elem;
	elem[i].intersect = s_intersect;
	while (i < list_elem -> quant[0])
	{
		elem[i].intersect(&elem[i], ray, list_elem -> intersect_l);
		i++;
	}
	return (hit(list_elem -> intersect_l));
}

t_elem	*hit(t_intersect_list *list)
{
	int		i;
	double	min;
	double	t_value;
	t_elem	*resp;

	i = -1;
	resp = NULL;
	min = INFINITY;
	while (i++ < list -> n)
	{
		t_value = list -> elem_inter[i].t;
		if (t_value > 0 && t_value < min)
		{
			min = list -> elem_inter[i].t;
			resp = list -> elem_inter[i].elem;
		}
	}
	printf("%p\n", resp);
	list -> n = 0;
	return (resp);
}
