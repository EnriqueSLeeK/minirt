/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_range_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:26 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/13 01:15:55 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	range_int_check(int *val, int n,
		int lower, int upper)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (val[i] < lower
			|| val[i] > upper)
			return (0);
		i += 1;
	}
	return (1);
}

int	range_double_check(double *val, int n,
		double lower, double upper)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (val[i] < lower
			|| val[i] > upper)
			return (0);
		i += 1;
	}
	return (1);
}
