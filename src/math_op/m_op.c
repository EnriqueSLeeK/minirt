/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:21 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 01:40:29 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Specialized matrix multiplication
// 1x4 * 4x4 => 1x4 
// m = matrix & t = tuple
double	*m_mult_t(double *matrix_p, double **matrix_s)
{
	double	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(double) * 4);
	while (i < 4)
	{
		result[i] = matrix_p[0] * matrix_s[i][0]
					+ matrix_p[1] * matrix_s[i][1]
					+ matrix_p[2] * matrix_s[i][2]
					+ matrix_p[3] * matrix_s[i][3];
		i++;
	}
	return (result);
}

// 0 == failure
double	**m_mult(double **matrix_p, double **matrix_s)
{
	double	**res;
	int		c;
	int		r;

	res = create_m(4);
	if (res == NULL)
		return (0);
	c = 0;
	r = 0;
	while (r < 4)
	{
		while (c < 4)
		{
			res[r][c] = matrix_p[r][0] * matrix_s[0][c]
				+ matrix_p[r][1] * matrix_s[1][c]
				+ matrix_p[r][2] * matrix_s[2][c]
				+ matrix_p[r][3] * matrix_s[3][c];
			c++;
		}
		r++;
		c = 0;
	}
	return (res);
}

int	matrix_cmp(double **matrix_p, double **matrix_s, int dim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < dim)
	{
		while (j < dim)
		{
			if (matrix_p[i][j] != matrix_s[i][j])
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

// Transpose m
double	**transpose_m(double **matrix, int dim)
{
	int		i;
	int		k;
	int		l;
	double	tmp;

	i = 0;
	k = 0;
	l = 0;
	while (i < dim)
	{
		while (k < dim)
		{
			if (i != k)
			{
				tmp = matrix[i][k];
				matrix[i][k] = matrix[k][i];
				matrix[k][i] = tmp;
			}
			k++;
		}
		i++;
		l++;
		k = l;
	}
	return (matrix);
}

// Return a inversed m matrix
double	**inverse_m(double **m, int dim)
{
	double	**inverse;
	double	factor;
	int		i;
	int		j;

	factor = det(m, dim);
	if (factor == 0)
		return (0);
	inverse = create_m(dim);
	if (inverse == NULL)
		return (0);
	matrix_cpy(inverse, m, dim);
	factor = 1 / factor;
	i = -1;
	j = -1;
	while (++i < dim)
	{
		while (++j < dim)
			inverse[i][j] = cof(m, i, j, dim) * factor;
		j = -1;
	}
	return (transpose_m(inverse, dim));
}
