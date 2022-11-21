/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:06:15 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 21:47:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	*position(t_ray *ray, double t)
{
	double	*res;
	double	*tmp;

	tmp = tsmult(ray -> dir, t);
	res = tadd(ray -> orig, tmp);
	free(tmp);
	return (res);
}
