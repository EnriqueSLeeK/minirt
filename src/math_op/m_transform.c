/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:59:14 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 02:50:01 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Matrix transformations

// Return a translation matrix
double	**translation(double x, double y, double z, double **m)
{
	double	**translation_m;

	translation_m = m;
	if (m == 0)
	{
		translation_m = create_m(4);
		if (translation_m == 0)
			return (0);
	}
	identity_m(translation_m, 4);
	translation_m[0][3] = x;
	translation_m[1][3] = y;
	translation_m[2][3] = z;
	return (translation_m);
}

// Return a scaling matrix
double	**scaling(double x, double y, double z, double **m)
{
	double	**scaling_m;

	scaling_m = m;
	if (m == 0)
	{
		scaling_m = create_m(4);
		if (scaling_m == 0)
			return (0);
	}
	identity_m(scaling_m, 4);
	scaling_m[0][0] = x;
	scaling_m[1][1] = y;
	scaling_m[2][2] = z;
	return (scaling_m);
}

double	**rotation_x(double rad, double **m)
{
	double	**rot_x;

	rot_x = m
	if (m == 0)
	{
		rot_x = create_m(4);
		if (rot_x == 0)
			return (0);
	}
	identity_m(rot_x, 4);
	rot_x[1][1] = cos(rad);
	rot_x[1][2] = - sin(rad);
	rot_x[2][2] = cos(rad);
	rot_x[2][1] = sin(rad);
	return (rot_x);
}

double	**rotation_y(double rad, double **m)
{
	double	**rot_y;

	rot_y = m;
	if (m == 0)
	{
		rot_y = create_m(4);
		if (rot_y == 0)
			return (0);
	}
	identity_m(rot_y, 4);
	rot_y[0][0] = cos(rad);
	rot_y[0][2] = sin(rad);
	rot_y[2][0] = - sin(rad);
	rot_y[2][2] = cos(rad);
	return (rot_y);
}

double	**rotation_z(double rad, double **m)
{
	double	**rot_z;

	rot_z = m;
	if (m == 0)
	{
		rot_z = create_m(4);
		if (rot_z == 0)
			return (0);
	}
	identity_m(rot_z, 4);
	rot_z[0][0] = cos(rad);
	rot_z[0][1] = - sin(rad);
	rot_z[1][0] = sin(rad);
	rot_z[1][1] = cos(rad);
	return (rot_z);
}
