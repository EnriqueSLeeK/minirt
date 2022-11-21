/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:26:20 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 22:45:48 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

void	s_intersect(t_elem *elem, t_ray *ray, t_intersect_list *i_list);
t_elem	*ray_shoot(t_list_elem *list_elem, t_ray *ray);
void	raytrace(t_list_elem *elem_list);
void	start_raytrace(t_list_elem *elem_list);

#endif
