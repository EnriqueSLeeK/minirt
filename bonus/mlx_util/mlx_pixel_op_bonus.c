/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_op_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:34:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 01:55:34 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	put_pixel(t_img *img, int row, int col, int color)
{
	char	*dst;

	dst = img->addr;
	dst += (row * img->len_line) + col * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_img *img, int x, int y)
{
	char		*img_pixel;

	img_pixel = img->addr;
	img_pixel += (y * img->len_line) + x * (img->bpp / 8);
	return (*(unsigned int *)img_pixel);
}
