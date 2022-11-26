/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:06:15 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/24 14:48:27 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	position(t_ray *ray, double t)
{
	t_tuple	mult;

	mult = tsmult(&ray -> dir, t);
	return (tadd(&mult, &ray -> orig));
}

t_ray	transform_ray(t_ray *ray, t_matrix *transform)
{
	t_ray	new_ray;

	new_ray.dir = m_mult_t(transform, &ray -> dir);
	new_ray.orig = m_mult_t(transform, &ray -> orig);
	return (new_ray);
}

t_ray	ray_to_object_space(t_ray *ray, t_matrix *transform)
{
	t_ray		new_ray;
	t_matrix	inv_matrix;

	inv_matrix = inverse_m(transform);
	/*
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%f ", inv_matrix.m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	new_ray.dir = m_mult_t(&inv_matrix, &ray -> dir);
	new_ray.orig = m_mult_t(&inv_matrix, &ray -> orig);
	return (new_ray);
}
