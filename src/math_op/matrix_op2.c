/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:54 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/11 23:53:39 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	determinant_m(double **matrix)
{
	return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}

double	**submatrix(double **matrix, int r, int c, int dim)
{
	double	**sub;
	int		sub_c[2];
	int		m_c[2];

	sub = matrix_create(dim - 1);
	if (!sub)
		return (0);
	set_to_zero(m_c, sub_c);
	while (m_c[0] < dim)
	{
		while (r != m_c[0] && m_c[1] < dim)
		{
			if (m_c[1] != c)
			{
				sub[sub_c[0]][sub_c[1]] = matrix[m_c[0]][m_c[1]];
				sub_c[1]++
			}
			m_c[1]++;
		}
		m_c[0]++;
		sub_c[0]++;
		sub_c[1] = 0;
		m_c[1] = 0;
	}
	return (sub);
}

static void	set_to_zero(double *m_c, double *s_c)
{
	m_c[0] = 0;
	m_c[1] = 0;
	sub_c[0] = 0;
	sub_c[1] = 0;
}
