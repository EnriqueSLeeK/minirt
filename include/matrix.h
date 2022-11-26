/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:52:06 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/25 01:48:53 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

// Matrix creation
t_matrix	create_m(int dim);

// Util function
void		matrix_cpy(t_matrix *m_d, t_matrix *m_s);
void		identity_m(t_matrix *matrix);

// Determinant calc
t_matrix	submatrix(t_matrix *matrix, int r, int c);
double		cof(t_matrix *matrix, int r, int c);
double		det(t_matrix *matrix);

// Matrix operations
t_matrix	inverse_m(t_matrix *m);
t_tuple		m_mult_t(t_matrix *matrix, t_tuple *tuple);
t_matrix	m_mult(t_matrix *matrix_p, t_matrix *matrix_s);
void		transpose_m(t_matrix *matrix);
int			matrix_cmp(t_matrix *matrix_p, t_matrix *matrix_s);

// Transformation
t_matrix	translation(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	rotation_x(double rad);
t_matrix	rotation_y(double rad);
t_matrix	rotation_z(double rad);

// Apply transform
void		set_transform(t_elem *elem, t_matrix transform);
t_matrix	view_transform(t_tuple *from, t_tuple *to, t_tuple *up);

#endif
