/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:15:16 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 23:33:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_LIST_H
# define INTERSECT_LIST_H

void				list_cpy(t_intersect *dst, t_intersect *src, int n);
void				add_intersect(t_intersect_list *ptr, t_elem *elem, double t);
void				resize_list(t_intersect_list *list);

t_intersect_list	*create_list(int size);
t_intersect			*hit(t_intersect_list *list);

#endif
