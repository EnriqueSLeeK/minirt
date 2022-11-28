/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:58 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 18:54:20 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	color_factor(double channel)
{
	if (channel > 1.0)
		channel = 1.0;
	else if (channel < 0.0)
		channel = 0.0;
	return (channel);
}

int	make_color(double r, double g, double b)
{
	int	l_r;
	int	l_g;
	int	l_b;

	l_r = 255.0 * color_factor(r);
	l_g = 255.0 * color_factor(g);
	l_b = 255.0 * color_factor(b);
	return (l_r << 16 | l_g << 8 | l_b);
}
