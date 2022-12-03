/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:59:14 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 15:10:23 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Matrix transformations

// Return a translation matrix
t_matrix	translation(double x, double y, double z)
{
	t_matrix	translation_m;

	translation_m = create_identity_m();
	translation_m.m[0][3] = x;
	translation_m.m[1][3] = y;
	translation_m.m[2][3] = z;
	return (translation_m);
}

// Return a scaling matrix
t_matrix	scaling(double x, double y, double z)
{
	t_matrix	scaling_m;

	scaling_m = create_identity_m();
	scaling_m.m[0][0] = x;
	scaling_m.m[1][1] = y;
	scaling_m.m[2][2] = z;
	return (scaling_m);
}

t_matrix	rotation_x(double rad)
{
	t_matrix	rot_x;

	rot_x = create_identity_m();
	rot_x.m[1][1] = cos(rad);
	rot_x.m[1][2] = -sin(rad);
	rot_x.m[2][1] = sin(rad);
	rot_x.m[2][2] = cos(rad);
	return (rot_x);
}

t_matrix	rotation_y(double rad)
{
	t_matrix	rot_y;

	rot_y = create_identity_m();
	rot_y.m[0][0] = cos(rad);
	rot_y.m[0][2] = sin(rad);
	rot_y.m[2][0] = -sin(rad);
	rot_y.m[2][2] = cos(rad);
	return (rot_y);
}

t_matrix	rotation_z(double rad)
{
	t_matrix	rot_z;

	rot_z = create_identity_m();
	rot_z.m[0][0] = cos(rad);
	rot_z.m[0][1] = -sin(rad);
	rot_z.m[1][0] = sin(rad);
	rot_z.m[1][1] = cos(rad);
	return (rot_z);
}
