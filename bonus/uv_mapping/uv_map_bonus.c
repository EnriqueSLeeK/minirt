/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:47:03 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 01:11:08 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	sphere_map(t_tuple *point, t_uv *uv)
{
	double	radius;
	double	raw_u;
	double	phi;

	raw_u = atan2(point->tup[0], point->tup[2]) / (2 * M_PI);
	radius = tmag(vector(point->tup[0], point->tup[1], point->tup[2]));
	phi = acos(point->tup[1] / radius);
	uv->u = 1.0 - (raw_u + 0.5);
	uv->v = 1.0 - (phi / M_PI);
}

void	plane_map(t_tuple *point, t_uv *uv)
{
	uv->u = fmod(point->tup[0], 1);
	uv->v = fmod(point->tup[2], 1);
}

void	cylinder_map(t_tuple *point, t_uv *uv)
{
	double	theta;
	double	raw_u;

	theta = atan2(point->tup[0], point->tup[2]);
	raw_u = theta / (2 * M_PI);
	uv->u = 1 - (raw_u + 0.5);
	uv->v = fmod(point->tup[1], 1);
}
