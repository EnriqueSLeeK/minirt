/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:26:11 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 22:48:55 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 4 size vector
double	*vec_init(double xr, double yg, double zb, double w)
{
	double	*vector;

	vector = malloc(sizeof(double) * 4);
	if (vector == 0)
		return (0);
	vector[0] = xr;
	vector[1] = yg;
	vector[2] = zb;
	vector[3] = w;
	return (vector);
}
