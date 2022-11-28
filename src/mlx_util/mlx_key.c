/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:03:54 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 02:39:08 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_key_event(int keycode, void *param)
{
	if (keycode == ESC)
		return (close_prog(param));
	return (0);
}

int	close_prog(void *param)
{
	t_list_elem	*elem_list;
	t_mlx		*mlx;

	elem_list = (t_list_elem *)param;
	mlx = &elem_list -> mlx_inf;
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_image(mlx -> mlx, mlx -> img);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	dealloc_mem(elem_list);
	exit(0);
	return (1);
}
