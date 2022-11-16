/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:03:54 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/26 23:07:56 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mlx_key_event(int keycode, void *param)
{
	if (keycode == ESC)
		return (close_prog(param));
}

int	close_prog(void *param)
{
	t_elem_list	*elem_list;
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	elem_list = (elem_lis *)param;
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_image(mlx -> mlx, mlx -> img);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	dealloc_mem(elem_list);
	exit(0);
}
