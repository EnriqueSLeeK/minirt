/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_s_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:05:04 by ensebast          #+#    #+#             */
/*   Updated: 2022/10/24 18:20:17 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	*tneg(double *tup)
{
	return (vec_init(-tup[0], -tup[1], -tup[2], -tup[3]));
}

// t = tuple; s = scalar; f = factor
double	*tsmult(double *tup, double f)
{
	return (vec_init(f * tup[0], f * tup[1], f * tup[2], f * tup[3]));
}

// Small optimization
double	*tsdiv(double *tup, double f)
{
	f = 1.0 / f;
	return (vec_init(f * tup[0], f * tup[1], f * tup[2], f * tup[3]));
}

double tmag(double *tup)
{
	return (sqrt(tup[0] * tup[0]
				+ tup[1] * tup[1]
				+ tup[2] * tup[2]
				+ tup[3] * tup[3]));
}

// Normalize
double *tnorm(double *tup)
{
	double	f;

	f = tmag(tup);
	if (f > 0)
	{
		return (tsmult(tup, f));
	}
	return (tup);
}
