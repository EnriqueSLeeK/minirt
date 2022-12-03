/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:09:51 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 18:12:52 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	dealloc_mem(t_list_elem *elem)
{
	free(elem -> elem);
	free(elem -> camera);
	free(elem -> light);
	free(elem -> ambient);
	free(elem -> intersect_l -> elem_inter);
	free(elem -> intersect_l);
}

void	dealloc_all_mem(t_list_elem *elem_list, t_mlx *mlx)
{
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_image(mlx -> mlx, mlx -> img);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	dealloc_mem(elem_list);
}
