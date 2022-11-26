/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:30:03 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/23 20:32:05 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Adding two point doesn't make any sense
// So the operation will applied to the w component too
t_tuple	tadd(t_tuple *t_one, t_tuple *t_two)
{
	return (create_t(t_one -> tup[0] + t_two -> tup[0],
				t_one -> tup[1] + t_two -> tup[1],
				t_one -> tup[2] + t_two -> tup[2],
				t_one -> tup[3] + t_two -> tup[3]));
}

t_tuple	tsub(t_tuple *t_one, t_tuple *t_two)
{
	return (create_t(t_one -> tup[0] - t_two -> tup[0],
				t_one -> tup[1] - t_two -> tup[1],
				t_one -> tup[2] - t_two -> tup[2],
				t_one -> tup[3] - t_two -> tup[3]));
}


// Cross product - vector op
t_tuple	tcross(t_tuple *t_one, t_tuple *t_two)
{
	return (create_t(t_one -> tup[1] * t_two -> tup[2]
				- t_one -> tup[2] * t_two -> tup[1],
				t_one -> tup[2] * t_two -> tup[0]
				- t_one -> tup[0] * t_two -> tup[2],
				t_one -> tup[0] * t_two -> tup[1]
				- t_one -> tup[1] * t_two -> tup[0],
				0));
}

// Dot product - vector op
// At least one should be normalize
double	tdot(t_tuple *t_one, t_tuple *t_two)
{
	return (t_one -> tup[0] * t_two -> tup[0]
			+ t_one -> tup[1] * t_two -> tup[1]
			+ t_one -> tup[2] * t_two -> tup[2]
			+ t_one -> tup[3] * t_two -> tup[3]);
}
