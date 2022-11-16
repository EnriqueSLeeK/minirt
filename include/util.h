/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:44:06 by ensebast          #+#    #+#             */
/*   Updated: 2022/09/27 16:45:33 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "struct.h"

int		alloc_mem(t_list_elem *buff, int *count);
void	dealloc_mem(t_list_elem *buff);
char	*get_line(int fd);
int		deg_to_rad(double *fov);
void	raytrace(t_list_elem *);

#endif
