/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_op_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:21 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 20:31:07 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

// Specialized matrix multiplication
// 4x4 * 4 x 1 => 4 x 1
// m = matrix & t = tuple
t_tuple	m_mult_t(t_matrix matrix, t_tuple tuple)
{
	t_tuple	res_t;
	int		i;

	i = 0;
	res_t = create_t(0, 0, 0, 0);
	while (i < 4)
	{
		res_t.tup[i] = tuple.tup[0] * matrix.m[i][0]
			+ tuple.tup[1] * matrix.m[i][1]
			+ tuple.tup[2] * matrix.m[i][2]
			+ tuple.tup[3] * matrix.m[i][3];
		i++;
	}
	return (res_t);
}

// 0 == failure
t_matrix	m_mult(t_matrix matrix_p, t_matrix matrix_s)
{
	t_matrix	result_m;
	int			c;
	int			r;

	c = 0;
	r = 0;
	result_m = create_m(matrix_p.size);
	while (r < matrix_p.size)
	{
		while (c < matrix_p.size)
		{
			result_m.m[r][c] = matrix_p.m[r][0] * matrix_s.m[0][c]
				+ matrix_p.m[r][1] * matrix_s.m[1][c]
				+ matrix_p.m[r][2] * matrix_s.m[2][c]
				+ matrix_p.m[r][3] * matrix_s.m[3][c];
			c++;
		}
		r++;
		c = 0;
	}
	return (result_m);
}

int	matrix_cmp(t_matrix matrix_p, t_matrix matrix_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < matrix_p.size)
	{
		while (j < matrix_p.size)
		{
			if (matrix_p.m[i][j] != matrix_s.m[i][j])
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

// Transpose m
t_matrix	transpose_m(t_matrix matrix)
{
	int		i[3];
	double	tmp;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (i[0] < matrix.size)
	{
		while (i[1] < matrix.size)
		{
			if (i[0] != i[1])
			{
				tmp = matrix.m[i[0]][i[1]];
				matrix.m[i[0]][i[1]] = matrix.m[i[1]][i[0]];
				matrix.m[i[1]][i[0]] = tmp;
			}
			i[1]++;
		}
		i[0]++;
		i[2]++;
		i[1] = i[2];
	}
	return (matrix);
}

// Return a inversed m matrix
t_matrix	inverse_m(t_matrix m)
{
	t_matrix	inverse;
	double		factor;
	int			i;
	int			j;

	factor = det(m);
	inverse = create_m(m.size);
	if (factor == 0)
		return (create_identity_m());
	matrix_cpy(&inverse, &m);
	factor = 1 / factor;
	i = -1;
	j = -1;
	while (++i < m.size)
	{
		while (++j < m.size)
			inverse.m[j][i] = cof(m, i, j) * factor;
		j = -1;
	}
	return (inverse);
}
