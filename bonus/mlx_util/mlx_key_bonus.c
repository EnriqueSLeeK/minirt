/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:03:54 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:17:24 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	mlx_key_event(int keycode, void *param)
{
	if (keycode == ESC)
		return (close_prog(param));
	return (0);
}

int	close_prog(void *param)
{
	t_list_elem	*elem_list;

	elem_list = (t_list_elem *)param;
	dealloc_all_mem(elem_list, &elem_list->mlx_inf);
	exit(0);
	return (1);
}

int	mlx_redraw(void *elem_list)
{
	t_mlx		*mlx_inf;
	t_list_elem	*list;

	list = (t_list_elem *)elem_list;
	mlx_inf = &(list->mlx_inf);
	mlx_put_image_to_window(mlx_inf -> mlx,
		mlx_inf -> win, mlx_inf -> img, 0, 0);
	return (0);
}
