/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:44:06 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 01:15:33 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "struct.h"

// Memory alloc
int		alloc_mem(t_list_elem *buff, int *count);
void	dealloc_mem(t_list_elem *buff);
void	dealloc_ray(t_ray *ray);

// Aux functions
char	*get_line(int fd);
int		deg_to_rad(double *fov);
int		make_color(double r, double g, double b);
int		cmp_float(double f, double s);

#endif
