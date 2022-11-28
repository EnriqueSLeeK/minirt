/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_orientation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:27:14 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 00:21:16 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fill_row(double *dst_row, double *row)
{
	dst_row[0] = row[0];
	dst_row[1] = row[1];
	dst_row[2] = row[2];
	dst_row[3] = 0;
}

// Aux values phase
// aux -> left -> true_up
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	orient_m;
	t_matrix	translation_m;
	t_tuple		forward;
	t_tuple		aux;

	orient_m = create_m(4);
	forward = tnorm(tsub(to, from));
	aux = tcross(forward, tnorm(up));
	fill_row(orient_m.m[0], aux.tup);
	aux = tcross(aux, forward);
	fill_row(orient_m.m[1], aux.tup);
	fill_row(orient_m.m[2], tneg(forward).tup);
	orient_m.m[3][0] = 0;
	orient_m.m[3][1] = 0;
	orient_m.m[3][2] = 0;
	orient_m.m[3][3] = 1;
	translation_m = translation(-from.tup[0], -from.tup[1], -from.tup[2]);
	orient_m = m_mult(orient_m, translation_m);
	return (orient_m);
}
