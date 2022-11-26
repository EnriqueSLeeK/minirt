/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:31:50 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 00:00:25 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect_list	*create_list(int size)
{
	t_intersect_list	*list_ptr;

	list_ptr = malloc(sizeof(t_intersect_list));
	list_ptr -> elem_inter = malloc(sizeof(t_intersect) * size);
	list_ptr -> size = size;
	list_ptr -> n = 0;
	return (list_ptr);
}

void	add_intersect(t_intersect_list *ptr, t_elem *elem, double t)
{
	(ptr -> elem_inter[ptr -> n]).elem = elem;
	(ptr -> elem_inter[ptr -> n]).t = t;
	ptr -> n += 1;
	if (ptr -> n >= ptr -> size)
		resize_list(ptr);
}

void	resize_list(t_intersect_list *list)
{
	t_intersect	*buff;

	list -> size *= 2;
	buff = malloc(sizeof(t_intersect) * list -> size);
	list_cpy(buff, list -> elem_inter, list -> n);
	free(list -> elem_inter);
	list -> elem_inter = buff;
}

void	list_cpy(t_intersect *dst, t_intersect *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}
