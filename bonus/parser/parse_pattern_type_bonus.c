/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pattern_type_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:21:56 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/05 11:48:55 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	set_pattern_type(void **buff, char *segment)
{
	int	**aux;

	aux = (int **)buff;
	if (ft_strncmp(segment, "checker_pattern", 16) == 0)
		**aux = PATTERN_CHECKBOARD;
	else if (ft_strncmp(segment, "bumpmap_pattern", 16) == 0)
		**aux = PATTERN_BUMP;
}
