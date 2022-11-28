/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_s_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:05:04 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 11:27:15 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tneg(t_tuple tup)
{
	return (create_t(-tup.tup[0],
				-tup.tup[1],
				-tup.tup[2],
				-tup.tup[3]));
}

// t = tuple; s = scalar; f = factor
t_tuple	tsmult(t_tuple tup, double f)
{
	return (create_t(f * tup.tup[0],
				f * tup.tup[1],
				f * tup.tup[2],
				f * tup.tup[3]));
}

// Small optimization
t_tuple	tsdiv(t_tuple tup, double f)
{
	f = 1.0 / f;
	return (create_t(f * tup.tup[0],
				f * tup.tup[1],
				f * tup.tup[2],
				f * tup.tup[3]));
}

// Length
double tmag(t_tuple tup)
{
	return (sqrt(tup.tup[0] * tup.tup[0]
				+ tup.tup[1] * tup.tup[1]
				+ tup.tup[2] * tup.tup[2]));
}

// Normalize
t_tuple	tnorm(t_tuple tup)
{
	double	f;

	f = 1 / tmag(tup);
	if (f > 0)
		return (tsmult(tup, f));
	return (tup);
}
