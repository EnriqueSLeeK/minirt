/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:48:55 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/23 22:45:05 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// Composite op
t_tuple		tadd(t_tuple *t_one, t_tuple *t_two);
t_tuple		tsub(t_tuple *t_one, t_tuple *t_two);
t_tuple		tcross(t_tuple *t_one, t_tuple *t_two);
double		tdot(t_tuple *t_one, t_tuple *t_two);

// Simple op
double		tmag(t_tuple *tup);
t_tuple		tnorm(t_tuple *tup);
t_tuple		tneg(t_tuple *tup);
t_tuple		tsdiv(t_tuple *tup, double f);
t_tuple		tsmult(t_tuple *tup, double f);

// Vector reflection
t_tuple		treflect(t_tuple *v, t_tuple *n);

// Tuple init
t_tuple		create_t(double xr, double yg, double zb, double w);

#endif
