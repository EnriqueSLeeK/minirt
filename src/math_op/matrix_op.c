/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:21 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/11 11:01:59 by ensebast         ###   ########.br       */
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

	result = malloc(sizeof(double) * 4);
	while (i < 4)
	{
		result[i] = matrix_p[i] * matrix_s[0][i]
					+ matrix_p[i] * matrix_s[1][i]
					+ matrix_p[i] * matrix_s[2][i]
					+ matrix_p[i] * matrix_s[3][i];
		i++;
	}
	return (result);
}

// 0 == failure
double	*m_mult(double **matrix_p, double **matrix_s)
{
	double	**res;
	int		c;
	int		r;

	res = matrix_create(4);
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

	i = 0;
	while (i < dim)
	{
		if (matrix_p[i][0] != matrix_s[i][0]
			||matrix_p[i][1] != matrix_s[i][1]
			||matrix_p[i][2] != matrix_s[i][2]
			||matrix_p[i][3] != matrix_s[i][3])
			return (0);
		i++;
	}
	return (1);
}

// Transpose m
void	transpose_m(double **matrix, int dim)
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
}

// Inverse m
/*
void	inverse_m(double **m, int dim)
{
}
*/
