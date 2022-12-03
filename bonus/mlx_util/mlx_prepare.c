/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_prepare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:38:26 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 17:32:27 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_prepare(t_mlx *mlx_info)
{
	mlx_info -> mlx = mlx_init();
	if (mlx_info -> mlx == NULL)
		return (1);
	mlx_info -> win = mlx_new_window(mlx_info -> mlx, WIDTH, HEIGHT, "minirt");
	if (mlx_info -> win == NULL)
	{
		mlx_destroy_display(mlx_info -> mlx);
		return (1);
	}
	mlx_info -> img = mlx_new_image(mlx_info -> mlx, WIDTH, HEIGHT);
	if (mlx_info -> img == NULL)
	{
		mlx_destroy_window(mlx_info -> mlx, mlx_info -> win);
		mlx_destroy_display(mlx_info -> mlx);
		return (1);
	}
	mlx_info -> img_inf.addr = mlx_get_data_addr(mlx_info -> img,
			&(mlx_info -> img_inf.bpp),
			&(mlx_info -> img_inf.len_line),
			&(mlx_info -> img_inf.endian));
	return (0);
}
