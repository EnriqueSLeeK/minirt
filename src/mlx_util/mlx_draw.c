/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:34:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 17:29:08 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_img *img, int row, int col, int color)
{
	char	*dst;

	dst = img -> addr;
	dst += (row * img -> len_line) + col * (img -> bpp / 8);
	*(unsigned int *)dst = color;
}
