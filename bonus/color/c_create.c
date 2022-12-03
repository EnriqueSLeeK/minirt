/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_create.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:22:48 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/23 22:46:55 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	create_c(double r, double g, double b)
{
	t_color	color;

	color.tup[0] = r;
	color.tup[1] = g;
	color.tup[2] = b;
	return (color);
}
