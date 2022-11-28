/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_det.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:54 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 11:13:22 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Plz consider "dim" as "size"

static void	fill_row(double *row, double *src_row, int c, int dim);

double	det(t_matrix matrix)
{
	int		j;
	double	d;

	if (matrix.size == 2)
		return ((matrix.m[0][0] * matrix.m[1][1]) - (matrix.m[0][1] * matrix.m[1][0]));
	j = 0;
	d = 0;
	while(j < matrix.size)
	{
		d += cof(matrix, 0, j) * matrix.m[0][j];
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

t_matrix	submatrix(t_matrix matrix, int r, int c)
{
	t_matrix	sub;
	int			m_r;
	int			s_r;

	sub = create_m(matrix.size - 1);
	s_r = 0;
	m_r = 0;
	while (m_r < matrix.size)
	{
		if (m_r != r)
		{
			fill_row(sub.m[s_r], matrix.m[m_r], c, matrix.size);
			s_r++;
		}
		m_r++;
	}
	return (sub);
}

double	cof(t_matrix matrix, int r, int c)
{
	double		sign;
	double		cofactor;
	t_matrix	minor;

	sign = 1;
	if ((r + c) % 2)
		sign = -1;
	minor = submatrix(matrix, r, c);
	cofactor = sign * det(minor);
	return (cofactor);
}
