/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:33:32 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 18:43:11 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	treflect(t_tuple v, t_tuple n)
{
	return (tsub(v, tsmult(n, 2.0 * tdot(v, n))));
}
