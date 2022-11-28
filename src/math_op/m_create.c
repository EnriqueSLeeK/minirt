/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_create.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:12:43 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/26 11:34:35 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 == success
// 0 == failure
// row (0) column (dim) will store the dim
t_matrix	create_m(int dim)
{
	t_matrix	m;

	m.size = dim;
	return (m);
}

t_matrix	create_identity_m(void)
{
	t_matrix	matrix;
	int			i;
	int			k;

	i = 0;
	k = 0;
	matrix.size = 4;
	while (i < matrix.size)
	{
		while (k < matrix.size)
		{
			matrix.m[i][k] = 0;
			if (i == k)
				matrix.m[i][k] = 1;
			k++;
		}
		i++;
		k = 0;
	}
	return (matrix);
}

void	identity_m(t_matrix *matrix)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < matrix -> size)
	{
		while (k < matrix -> size)
		{
			matrix -> m[i][k] = 0;
			if (i == k)
				matrix -> m[i][k] = 1;
			k++;
		}
		i++;
		k = 0;
	}
}

// Copy matrix
void	matrix_cpy(t_matrix *m_d, t_matrix *m_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m_d -> size)
	{
		while (j < m_d -> size)
		{
			m_d -> m[i][j] = m_s -> m[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}
