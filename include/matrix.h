/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:52:06 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 21:11:22 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

// Memory
double	**create_m(int dim);
void	destroy_m(double **m, int i);


// Some actions
void	identity_m(double **m, int dim);
void	matrix_cpy(double **m_d, double **m_s, int dim);

double	**inverse_m(double **m, int dim);
double	**transpose_m(double **matrix, int dim);
int		matrix_cmp(double **matrix_p, double **matrix_s, int dim);

// multiplication with tuple
double	*m_mult_t(double *matrix_p, double **matrix_s);

// multiplication with square matrix
double	**m_mult(double **matrix_p, double **matrix_s);

double	det(double **matrix, int dim);
double	cof(double **matrix, int r, int c, int dim);
double	**submatrix(double **matrix, int r, int c, int dim);

// Transformations
double	**translation(double x, double y, double z);
double	**scaling(double x, double y, double z);

double	**rotation_x(double rad);
double	**rotation_y(double rad);
double	**rotation_z(double rad);

#endif
