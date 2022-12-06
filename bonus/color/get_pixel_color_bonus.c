/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:02:02 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 01:53:20 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static t_color	unpack_color(unsigned int packed_color)
{
	unsigned int	mask;
	double			factor;
	t_color			color;

	mask = 0xff;
	factor = 1.0 / 255.0;
	color.tup[2] = (packed_color & mask) * factor;
	color.tup[1] = ((packed_color & (mask << 8)) >> 8) * factor;
	color.tup[0] = ((packed_color & (mask << 16)) >> 16) * factor;
	return (color);
}

t_color	get_pixel_color(t_img *img, int x, int y)
{
	t_color	color;

	color = unpack_color(get_pixel(img, x, y));
	return (color);
}
