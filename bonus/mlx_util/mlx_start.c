/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:41:52 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 18:33:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_start(t_list_elem *elem_list)
{
	t_mlx	*mlx_inf;

	mlx_inf = &(elem_list -> mlx_inf);
	mlx_key_hook(mlx_inf -> win, mlx_key_event, elem_list);
	mlx_expose_hook(mlx_inf -> win, mlx_redraw, elem_list);
	mlx_hook(mlx_inf -> win, DestroyNotify, ButtonPressMask,
		close_prog, elem_list);
	mlx_put_image_to_window(mlx_inf -> mlx,
		mlx_inf -> win, mlx_inf -> img, 0, 0);
	mlx_loop(mlx_inf -> mlx);
}
