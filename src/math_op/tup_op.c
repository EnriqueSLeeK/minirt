/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:30:03 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 21:13:06 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Adding two point doesn't make any sense
// So the operation will applied to the w component too
double	*tadd(double *t_one, double *t_two)
{
	return (vec_init(t_one[0] + t_two[0],
				t_one[1] + t_two[1],
				t_one[2] + t_two[2],
				t_one[3] + t_two[3]));
}

double	*tsub(double *t_one, double *t_two)
{
	return (vec_init(t_one[0] - t_two[0],
				t_one[1] - t_two[1],
				t_one[2] - t_two[2],
				t_one[3] - t_two[3]));
}

// Dot product - vector op
// At least one should be normalize
double	tdot(double *t_one, double *t_two)
{
	return (t_one[0] * t_two[0] + t_one[1] * t_two[1]
				+ t_one[2] * t_two[2] + t_one[3] * t_two[3]);
}

// Cross product - vector op
double	*tcross(double *t_one, double *t_two)
{
	return (vec_init(t_one[1] * t_two[2] - t_one[2] * t_two[1],
			t_one[2] * t_two[0] - t_one[0] * t_two[2],
			t_one[0] * t_two[1] - t_one[1] * t_two[0],
			0));
}

// Color mult - color op
double	*cmult(double *c_one, double *c_two)
{
	return (vec_init(c_one[0] * c_two[0],
				c_one[1] * c_two[1],
				c_one[2] * c_two[2],
				1));
}
