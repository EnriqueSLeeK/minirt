/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:48:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/10/24 13:56:20 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// Composite op
double	*vec_sum(double *v_f, double *v_s);
double	*vec_sub(double *v_f, double *v_s);
double	*vec_cross(double *v_f, double *v_s);
double	vec_dot(double *v_f, double *v_s);

// Simple op
double	vec_len(double *v);
double	*vec_norm(double *v);
double	vec_square_len(double *v);
double	*vec_scalar_prod(double *v, double f);
double	*vec_scalar_div(double *v, double f);

// Vector init
double	*vec_init(double xr, double yg, double zb, double w);

#endif
