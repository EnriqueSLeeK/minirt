/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:26:11 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/22 16:53:38 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Create a tuple 4
t_tuple	create_t(double xr, double yg, double zb, double w)
{
	t_tuple	tuple;

	tuple.tup[0] = xr;
	tuple.tup[1] = yg;
	tuple.tup[2] = zb;
	tuple.tup[3] = w;
	return (tuple);
}
