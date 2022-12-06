/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:30:18 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:17:24 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	intersect_pl(t_elem *elem, t_ray *ray, t_intersect_list *i_list)
{
	double	t;

	if (fabs(ray -> dir.tup[1]) < EPSILON)
		return ;
	t = (-ray -> orig.tup[1]) / ray -> dir.tup[1];
	add_intersect(i_list, elem, t);
}
