/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:09:51 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 17:56:36 by ensebast         ###   ########.br       */
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
