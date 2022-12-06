/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:41:52 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:15:39 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	str_to_int(char *i_str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*i_str == '-')
	{
		sign = -1;
		i_str += 1;
	}
	while (*i_str)
	{
		num = (num * 10) + *i_str - '0';
		i_str += 1;
	}
	num *= sign;
	return (num);
}
