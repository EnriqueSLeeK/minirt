/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:29:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/23 22:48:06 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

t_color	cmult(t_color *c_one, t_color *c_two);
t_color	cadd(t_color *c_one, t_color *c_two);
t_color	csub(t_color *c_one, t_color *c_two);

t_color	csmult(t_color *color, double f);

t_color	create_c(double r, double g, double b);

#endif
