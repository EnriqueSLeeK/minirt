/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:58 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:17:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	rgb(double channel)
{
	int	c;

	c = (int)(channel * 255.0);
	if (c > 255)
		return (255);
	else if (c < 0)
		return (0);
	return (c);
}

int	make_color(double r, double g, double b)
{
	int	l_r;
	int	l_g;
	int	l_b;

	l_r = rgb(r);
	l_g = rgb(g);
	l_b = rgb(b);
	return (l_r << 16 | l_g << 8 | l_b);
}
