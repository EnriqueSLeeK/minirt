/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:58 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/29 14:12:01 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	ratio_to_literal(double *ratio, int *buff)
{
	buff[0] = 255.999 * ratio[0];
	buff[1] = 255.999 * ratio[1];
	buff[2] = 255.999 * ratio[2];
}

int	make_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
