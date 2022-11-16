/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:34:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/29 15:24:52 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img -> addr + (y * img -> len_line + x * (img -> bpp / 8));
	*(unsigned int *)dst = color;
}
