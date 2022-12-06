/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_double_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:48:33 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:15:34 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	point_adjust(double *number, int times)
{
	while (times > 0)
	{
		*number /= 10;
		times -= 1;
	}
}

static double	action(char *d_str, double sign)
{
	double	num;
	int		i;
	int		len;
	int		dot_pos;

	i = 0;
	num = 0;
	len = 0;
	dot_pos = -1;
	while (d_str[i])
	{
		if (d_str[i] == '.')
			dot_pos = i;
		else
		{
			len += 1;
			num = (num * 10) + (d_str[i] - '0');
		}
		i++;
	}
	if (dot_pos > -1)
		point_adjust(&num, len - dot_pos);
	num *= sign;
	return (num);
}

double	str_to_double(char *d_str)
{
	double	sign;

	sign = 1;
	if (*d_str == '-')
	{
		d_str += 1;
		sign = -1;
	}
	return (action(d_str, sign));
}
