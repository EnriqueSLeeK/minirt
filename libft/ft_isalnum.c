/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:23:17 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int elem)
{
	if (ft_isalpha(elem) || ft_isdigit(elem))
		return (8);
	return (0);
}
