/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:58:49 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/29 14:35:50 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Prepare mlx and start raytracing
void	raytrace(t_list_elem *list_elem)
{
	//start_raytrace(list_elem);
	printf("Elem:    %d\n", list_elem -> quant[0]);
	printf("Light:   %d\n", list_elem -> quant[1]);
	printf("Ambient: %d\n", list_elem -> quant[2]);
	printf("Camera:  %d\n", list_elem -> quant[3]);
}

/*
 * coord [0] = x
 * coord [1] = y
void	start_raytrace(t_list_elem *list_elem)
{
	double	coord[2];

	coord[0] = 0;
	coord[1] = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_draw(list_elem -> , coord[0], coord[1], hit_obj(list_elem));
			x++;
		}
		y++;
		x = 0;
	}
}

// When a object is hit return the color
int	hit_obj(t_list_elem *list_elem)
{

}
*/
