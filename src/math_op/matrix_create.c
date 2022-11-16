/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:12:43 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/11 11:11:32 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// 1 == success
// 0 == failure
// row (0) column (dim) will store the dim
double	**create_m(int dim)
{
	double	**matrix;
	int		i;

	if (dim < 1)
		return (0);
	matrix = malloc(sizeof(double *) * dim);
	if (matrix == NULL)
		return (0);
	matrix[0] = malloc((sizeof(double) * dim) + 1);
	i = 1;
	while (i < dim)
	{
		matrix[i] = malloc(sizeof(double) * dim);
		if (matrix[i] == NULL)
		{
			matrix_destruction(matrix, i);
			return (0);
		}
		i++;
	}
	matrix[0][dim] = dim;
	return (matrix);
}

// Take a pre-alloc matrix then contruct a ident m
void	identity_m(double **m, int dim)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < dim)
	{
		while (k < dim)
		{
			m[i][k] = 0;
			if (i == k)
				m[i][k] = 1;
			k++;
		}
		i++;
		k = 0;
	}
}

void	destruction_m(double **m, int i)
{
	int	k;

	k = 0;
	while (k <= i)
	{
		free(m[k]);
		k++;
	}
	free(m);
}
