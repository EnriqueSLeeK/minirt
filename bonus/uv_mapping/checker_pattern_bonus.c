/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pattern_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:48:13 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 23:51:53 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_color	checker_pattern(t_texture *pattern, t_uv uv)
{
	unsigned long int	u;
	unsigned long int	v;

	u = floor(uv.u * pattern->width);
	v = floor(uv.v * pattern->height);
	if ((u + v) % 2)
		return (pattern->color_a);
	return (pattern->color_b);
}
