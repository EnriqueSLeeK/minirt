/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:47:44 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/02 21:02:36 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Default setting for the material
t_material	material(t_color *color, t_ambient *ambient)
{
	t_material	mat;

	mat.color = color;
	mat.ambient = ambient->color;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200.0;
	return (mat);
}

void	set_material(t_list_elem *list_elem)
{
	int	i;

	i = -1;
	while (++i < list_elem -> quant[0])
	{
		list_elem->elem[i].material = material(
				&list_elem->elem[i].color,
				list_elem->ambient);
	}
}
