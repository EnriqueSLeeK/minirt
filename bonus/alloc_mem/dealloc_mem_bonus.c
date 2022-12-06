/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc_mem_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:09:51 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 15:33:14 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	dealloc_mem_img(t_elem *elem, int quant, void *mlx)
{
	int	i;

	i = -1;
	while (++i < quant)
	{
		if (elem[i].pattern_type == PATTERN_BUMP
			&& elem[i].texture.img != NULL)
			mlx_destroy_image(mlx, elem[i].texture.img);
	}
}

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
	dealloc_mem_img(elem_list->elem, elem_list->quant[0], mlx->mlx);
	mlx_destroy_window(mlx -> mlx, mlx -> win);
	mlx_destroy_image(mlx -> mlx, mlx -> img);
	mlx_destroy_display(mlx -> mlx);
	free(mlx -> mlx);
	dealloc_mem(elem_list);
}
