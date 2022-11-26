/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_orietation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:27:14 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 01:48:59 by ensebast         ###   ########.br       */
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
// aux -> upn -> left -> true_up
t_matrix	view_transformn(t_tuple *from, t_tuple *to, t_tuple *up)
{
	t_matrix	transformation_m;
	t_matrix	translation_m;
	t_tuple		forward;
	t_tuple		aux;

	transformation_m = create_m(4);
	forward = tsub(to, from);
	forward = tnorm(&forward);
	aux = tnorm(up);
	aux = tcross(&forward, &aux);
	fill_row(transformation_m.m[0], aux.tup);
	aux = tcross(&aux, &forward);
	fill_row(transformation_m.m[1], aux.tup);
	forward = tneg(&forward);
	fill_row(transformation_m.m[2], forward.tup);
	transformation_m.m[3][0] = 0;
	transformation_m.m[3][1] = 0;
	transformation_m.m[3][2] = 0;
	transformation_m.m[3][3] = 1;
	translation_m = translation(- from -> tup[0], - from -> tup[1],
			- from -> tup[2]);
	return (m_mult(&transformation_m, &translation_m));
}
