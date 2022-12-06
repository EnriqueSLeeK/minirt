/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:47:44 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 15:19:14 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Default setting for the material
t_material	material(void)
{
	t_material	mat;

	mat.color = create_c(0, 0, 0);
	mat.ambient = create_c(1, 1, 1);
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 200.0;
	return (mat);
}

void	set_ambient(t_elem *elem, t_ambient *ambient, int quant)
{
	int	i;

	i = -1;
	while (++i < quant)
		elem[i].material.ambient = ambient->color;
}
