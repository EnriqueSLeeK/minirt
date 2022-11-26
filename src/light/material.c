/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:47:44 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/24 03:20:50 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Default setting for the material
t_material	material(t_color *color, t_ambient *ambient)
{
	t_material	mat;

	mat.color = color;
	mat.ambient = ambient;
	mat.diffuse = 0.9;
	mat.specular = 0.9;
	mat.shininess = 50.0;
	return (mat);
}
