/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_pattern_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:13:09 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 13:11:54 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	cmp_color(t_color a, t_color b)
{
	if (cmp_float(a.tup[0], b.tup[0])
		&& cmp_float(a.tup[1], b.tup[1])
		&& cmp_float(a.tup[2], b.tup[2]))
		return (1);
	return (0);
}

void	prep_checker(t_elem *elem)
{
	t_color	color_a;
	t_color	color_b;

	elem->texture.img = NULL;
	elem->material.specular = 0.1;
	color_a = elem->material.color;
	color_b = csub(create_c(1.0, 1.0, 1.0), color_a);
	if (cmp_color(color_a, color_b))
		color_b = create_c(1.0, 1.0, 1.0);
	elem->texture.color_a = color_a;
	elem->texture.color_b = color_b;
}

int	prep_img(t_elem *elem, void *mlx, char *filename)
{
	elem->texture.img = mlx_xpm_file_to_image(mlx,
			filename, &elem->texture.width,
			&elem->texture.height);
	if (elem->texture.img == NULL)
		return (0);
	elem->texture.img_inf.addr = mlx_get_data_addr(
			elem->texture.img,
			&(elem->texture.img_inf.bpp),
			&(elem->texture.img_inf.len_line),
			&(elem->texture.img_inf.endian));
	elem->material.specular = 0.0;
	return (1);
}
