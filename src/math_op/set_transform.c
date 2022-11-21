/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:00:06 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 01:28:50 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*set_transform(t_ray *ray, double **m_transform)
{
	t_ray *new_ray;

	new_ray = malloc(sizeof(t_ray));
	new_ray -> orig = m_mult_t(ray -> orig, m_transform);
	new_ray -> dir = m_mult_t(ray -> dir, m_transform);
	return (new_ray);
}
