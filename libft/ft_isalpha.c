/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:18 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int elem)
{
	if ((elem >= 'a' && elem <= 'z')
		|| (elem >= 'A' && elem <= 'Z'))
		return (1024);
	return (0);
}
