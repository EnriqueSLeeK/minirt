/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:18:45 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/23 22:33:05 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_OP_H
# define RAY_OP_H

t_tuple	position(t_ray *ray, double t);

t_ray	transform_ray(t_ray *ray, t_matrix *transform);

t_ray	ray_to_object_space(t_ray *ray, t_matrix *transform);

#endif
