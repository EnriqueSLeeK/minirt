/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:47:53 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/02 21:17:31 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	prep_sp(t_aux_parse *info, t_elem *elem)
{
	t_matrix	aux;
	double		radius;

	elem->color = info->color;
	elem->intersect = intersect_s;
	elem->local_normal = normal_sp;
	aux = translation(info->coord.tup[0],
			info->coord.tup[1],
			info->coord.tup[2]);
	radius = info->diameter * 0.5;
	aux = m_mult(aux, scaling(radius, radius, radius));
	set_transform(elem, aux);
}

void	prep_pl(t_aux_parse *info, t_elem *elem)
{
	t_matrix	rot;
	t_matrix	aux;

	elem->color = info->color;
	elem->intersect = intersect_pl;
	elem->local_normal = normal_pl;
	aux = translation(info->coord.tup[0],
			info->coord.tup[1],
			info->coord.tup[2]);
	aux = m_mult(aux, shape_orientation(info->norm_vec));
	set_transform(elem, aux);
}

void	prep_cy(t_aux_parse *info, t_elem *elem)
{
	t_matrix	trans;
	t_matrix	rot;
	t_matrix	scale;
	double		radius;

	elem->color = info->color;
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
}
