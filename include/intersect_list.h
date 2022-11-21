/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:15:16 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 21:24:59 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_LIST_H
# define INTERSECT_LIST_H

// Create a dynamic array
t_intersect_list	*create_list(int size);

// Add a element to the array
void				add_intersect(t_intersect_list *ptr, t_elem *elem, double t);

// List resize util
void				resize_list(t_intersect_list *list);
void				list_cpy(t_intersect *dst, t_intersect *src, int n);

t_elem				*hit(t_intersect_list *list);

#endif
