/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_det.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:54 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/17 00:03:11 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Plz consider "dim" as "size"

static void	fill_row(double *row, double *src_row, int c, int dim);

double	det(double **matrix, int dim)
{
	int		j;
	double	d;

	if (dim == 1)
		return (matrix[0][0]);
	else if (dim == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	j = 0;
	d = 0;
	while(j < dim)
	{
		d += cof(matrix, 0, j, dim) * matrix[0][j];
		j++;
	}
	return (d);
}

static void	fill_row(double *row, double *src_row, int c, int dim)
{
	int	j;
	int	s_j;

	j = 0;
	s_j = 0;
	while (j < dim)
	{
		if (c != j)
		{
			row[s_j] = src_row[j];
			s_j++;
		}
		j++;
	}
}

double	**submatrix(double **matrix, int r, int c, int dim)
{
	double	**sub;
	int		m_r;
	int		s_r;

	sub = create_m(dim - 1);
	if (!sub)
		return (0);
	s_r = 0;
	m_r = 0;
	while (m_r < dim)
	{
		if (m_r != r)
		{
			fill_row(sub[s_r], matrix[m_r], c, dim);
			s_r++;
		}
		m_r++;
	}
	return (sub);
}

double	cof(double **matrix, int r, int c, int dim)
{
	double	sign;
	double	**minor;
	double	cofactor;

	sign = 1;
	if ((r + c) % 2)
		sign = -1;
	minor = submatrix(matrix, r, c, dim);
	cofactor = sign * det(minor, dim - 1);
	destroy_m(minor, dim - 1);
	return (cofactor);
}
