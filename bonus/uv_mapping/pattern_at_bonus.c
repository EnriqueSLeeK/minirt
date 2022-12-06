/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_at_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:23:56 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 01:55:10 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	limit_coord(int *coord, int min, int max)
{
	if (*coord > max)
		*coord = max;
	else if (*coord < min)
		*coord = min;
}

t_color	pattern_at_img(t_elem *elem, t_tuple w_p)
{
	t_tuple	o_p;
	t_uv	uv;
	int		x;
	int		y;

	o_p = m_mult_t(elem->inv_transform, w_p);
	elem->uv_mapping(&o_p, &uv);
	x = uv.u * (elem->texture.width - 1);
	y = uv.v * (elem->texture.height - 1);
	limit_coord(&x, 0, elem->texture.width - 1);
	limit_coord(&y, 0, elem->texture.height - 1);
	return (get_pixel_color(&elem->texture.img_inf, x, y));
}

t_color	pattern_at_uv(t_elem *elem, t_tuple w_p)
{
	t_uv	uv;
	t_tuple	o_p;

	o_p = m_mult_t(elem->inv_transform, w_p);
	elem->uv_mapping(&o_p, &uv);
	return (checker_pattern(&elem->texture, uv));
}
