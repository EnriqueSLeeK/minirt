/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:26:20 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 23:32:11 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

// Computation contructor
t_computation	prepare_computation(t_intersect *inter, t_ray *ray);

// Sphere normal
t_tuple			normal_at_s(t_elem *, t_tuple *);

// ray shooting and hit in general
void			raytrace(t_list_elem *elem_list);
void			start_raytrace(t_list_elem *elem_list);
t_intersect		*ray_shoot(t_list_elem *list_elem, t_ray *ray);

// Intersection functions
// Sphere:
void			intersect_s(t_elem *elem, t_ray *ray, t_intersect_list *i_list);
#endif
