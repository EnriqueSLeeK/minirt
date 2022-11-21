/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:26:20 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 00:51:02 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

// Intersection functions
void	intersect_s(t_elem *elem, t_ray *ray, t_intersect_list *i_list);

// Sphere normal
double	*normal_at_s(t_elem *elem, double *p);

// ray shooting and hit in general
void	raytrace(t_list_elem *elem_list);
void	start_raytrace(t_list_elem *elem_list);
t_elem	*ray_shoot(t_list_elem *list_elem, t_ray *ray);

#endif
