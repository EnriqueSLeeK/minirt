/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:02:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 16:52:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * quant index meaning
 * 0 - elem quant
 * 1 - light quant
 * 3 - camera quant
 */
int	alloc_mem(t_list_elem *elem_ptr, int *quant)
{
	elem_ptr -> elem = malloc(sizeof(t_elem) * quant[0]);
	elem_ptr -> light = malloc(sizeof(t_light) * quant[1]);
	elem_ptr -> ambient = malloc(sizeof(t_ambient) * quant[2]);
	elem_ptr -> camera = malloc(sizeof(t_camera) * quant[3]);
	elem_ptr -> intersect_l = create_list(32);
	if (!(elem_ptr -> elem && elem_ptr -> light
		&& elem_ptr -> ambient && elem_ptr -> camera))
	{
		dealloc_mem(elem_ptr);
		return (1);
	}
	ft_memset(elem_ptr -> elem, 0, sizeof(t_elem) * quant[0]);
	ft_memset(elem_ptr -> light, 0, sizeof(t_light) * quant[1]);
	ft_memset(elem_ptr -> ambient, 0, sizeof(t_ambient) * quant[2]);
	ft_memset(elem_ptr -> camera, 0, sizeof(t_camera) * quant[3]);
	ft_memset(elem_ptr -> intersect_l -> elem_inter, 0,
		sizeof(t_intersect) * 32);
	return (0);
}
