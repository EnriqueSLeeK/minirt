/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_reflect_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:33:32 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 21:17:21 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_tuple	treflect(t_tuple v, t_tuple n)
{
	return (tsub(v, tsmult(n, 2.0 * tdot(v, n))));
}
