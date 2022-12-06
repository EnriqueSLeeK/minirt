/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_float_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:23:56 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:17:24 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

// Compare two float number
// 1 -> true
// 0 -> false
int	cmp_float(double f_one, double f_two)
{
	if (fabs(f_one - f_two) < EPSILON)
		return (1);
	return (0);
}
