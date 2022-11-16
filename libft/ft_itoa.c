/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:18 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:10 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num_mag(int n)
{
	int	k;
	int	tmp;
	int	ten_pow;

	k = 2;
	if (n < 0)
		k += 1;
	ten_pow = 1;
	tmp = n / ten_pow;
	while (!(tmp > -10 && tmp < 10))
	{
		ten_pow *= 10;
		tmp = n / ten_pow;
		k += 1;
	}
	return (k);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		leng;
	int		i;

	if (n == 0)
	{
		result = ft_calloc(1, 2);
		result[0] = '0';
		return (result);
	}
	leng = ft_get_num_mag(n);
	i = leng - 2;
	result = ft_calloc (1, leng);
	if (result == 0)
		return (0);
	while (i > -1)
	{
		result[i] = (ft_abs(n % 10)) + '0';
		n /= 10;
		i -= 1;
	}
	if (result[0] == '0')
		result[0] = '-';
	return (result);
}
