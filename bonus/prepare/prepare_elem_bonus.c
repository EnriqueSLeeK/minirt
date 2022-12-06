/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_elem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:47:53 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 19:24:41 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	prep_pattern(t_elem *elem, void *mlx, char *filename,
		void (*mapping)(t_tuple *o_p, t_uv *uv))
{
	elem->uv_mapping = mapping;
	if (elem -> pattern_type == PATTERN_BUMP)
	{
		if (*filename == 0)
			return (0);
		return (prep_img(elem, mlx, filename));
	}
	else if (elem -> pattern_type == PATTERN_CHECKBOARD)
		prep_checker(elem);
	return (1);
}

int	prep_sp(t_aux_parse *info, t_elem *elem, void *mlx)
{
	t_matrix	aux;
	double		radius;

	elem->material = material();
	elem->material.color = info->color;
	elem->intersect = intersect_s;
	elem->local_normal = normal_sp;
	aux = translation(info->coord.tup[0],
			info->coord.tup[1],
			info->coord.tup[2]);
	radius = info->diameter * 0.5;
	aux = m_mult(aux, scaling(radius, radius, radius));
	set_transform(elem, aux);
	elem -> pattern_type = info -> pattern_type;
	if (elem -> pattern_type != 0)
		return (prep_pattern(elem, mlx, info->filename, sphere_map));
	return (1);
}

int	prep_pl(t_aux_parse *info, t_elem *elem, void *mlx)
{
	t_matrix	aux;

	elem->material = material();
	elem->material.color = info->color;
	elem->intersect = intersect_pl;
	elem->local_normal = normal_pl;
	aux = translation(info->coord.tup[0],
			info->coord.tup[1],
			info->coord.tup[2]);
	aux = m_mult(aux, shape_orientation(info->norm_vec));
	set_transform(elem, aux);
	elem -> pattern_type = info -> pattern_type;
	if (elem -> pattern_type != 0)
		return (prep_pattern(elem, mlx, info->filename, plane_map));
	return (1);
}

int	prep_cy(t_aux_parse *info, t_elem *elem, void *mlx)
{
	t_matrix	trans;
	t_matrix	rot;
	t_matrix	scale;
	double		radius;

	elem->material = material();
	elem->material.color = info->color;
	elem->intersect = intersect_cy;
	elem->local_normal = normal_cy;
	radius = info->diameter * 0.5;
	trans = translation(info->coord.tup[0],
			info->coord.tup[1],
			info->coord.tup[2]);
	scale = scaling(radius, 1, radius);
	rot = shape_orientation(info->norm_vec);
	set_transform(elem, m_mult(m_mult(trans, rot), scale));
	elem->max = info->height / 2;
	elem->min = -elem->max;
	elem -> pattern_type = info -> pattern_type;
	if (elem -> pattern_type != 0)
		return (prep_pattern(elem, mlx, info->filename, cylinder_map));
	return (1);
}

int	prep_cn(t_aux_parse *info, t_elem *elem, void *mlx)
{
	t_matrix	trans;
	t_matrix	rot;
	t_matrix	scale;
	double		factor;

	elem->material = material();
	elem->material.color = info->color;
	elem->intersect = intersect_cn;
	elem->local_normal = normal_cn;
	factor = info->diameter / info->height;
	trans = translation(info->coord.tup[0],
			info->coord.tup[1],
			info->coord.tup[2]);
	scale = scaling(factor, 1, factor);
	rot = shape_orientation(info->norm_vec);
	set_transform(elem, m_mult(m_mult(trans, rot), scale));
	elem->max = info->height / 2;
	elem->min = -elem->max;
	elem -> pattern_type = info -> pattern_type;
	if (elem -> pattern_type != 0)
		return (prep_pattern(elem, mlx, info->filename, cylinder_map));
	return (1);
}
