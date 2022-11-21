/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:48:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 21:48:15 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// Composite op
double	*tadd(double *v_f, double *v_s);
double	*tsub(double *v_f, double *v_s);
double	*tcross(double *v_f, double *v_s);
double	tdot(double *v_f, double *v_s);

// Simple op
double	tmag(double *v);
double	*tnorm(double *v);
double	*tneg(double *v);
double	*tsdiv(double *v, double f);
double	*tsmult(double *v, double f);

// Vector init
double	*vec_init(double xr, double yg, double zb, double w);

#endif
