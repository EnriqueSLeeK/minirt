/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:47:44 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 19:09:24 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

// Default setting for the material
t_material	material(void)
{
	t_material	mat;

	mat.color = create_c(1, 1, 1);
	mat.ambient = create_c(1, 1, 1);
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200.0;
	return (mat);
}

void	set_ambient(t_ambient *ambient, t_elem *elem, int quant)
{
	int	i;

	i = -1;
	while (++i < quant)
		elem[i].material.ambient = ambient->color;
}
