/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:26:11 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 11:23:53 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Create a tuple 4
t_tuple	create_t(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.tup[0] = x;
	tuple.tup[1] = y;
	tuple.tup[2] = z;
	tuple.tup[3] = w;
	return (tuple);
}

t_tuple	point(double x, double y, double z)
{
	return (create_t(x, y, z, 1));
}

t_tuple	vector(double x, double y, double z)
{
	return (create_t(x, y, z, 0));
}
