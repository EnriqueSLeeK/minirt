/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:33:32 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/23 01:33:46 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	treflect(t_tuple *v, t_tuple *n)
{
	t_tuple	ref;
	double	factor;

	factor = 2 * tdot(v, n);
	ref = tsmult(n, factor);
	ref = tsub(v, &ref);
	return (ref);
}
