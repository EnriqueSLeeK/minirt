/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:24:39 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 12:05:18 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Color mult - color op
t_color	cmult(t_color c_one, t_color c_two)
{
	return (create_c(c_one.tup[0] * c_two.tup[0],
				c_one.tup[1] * c_two.tup[1],
				c_one.tup[2] * c_two.tup[2]));
}

t_color	cadd(t_color c_one, t_color c_two)
{
	return (create_c(c_one.tup[0] + c_two.tup[0],
				c_one.tup[1] + c_two.tup[1],
				c_one.tup[2] + c_two.tup[2]));
}

t_color	csmult(t_color color, double f)
{
	return (create_c(color.tup[0] * f,
				color.tup[1] * f,
				color.tup[2] * f));
}

t_color	csub(t_color c_one, t_color c_two)
{
	return (create_c(c_one.tup[0] - c_two.tup[0],
				c_one.tup[1] - c_two.tup[1],
				c_one.tup[2] - c_two.tup[2]));
}
