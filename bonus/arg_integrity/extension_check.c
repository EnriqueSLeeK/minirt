/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:53:40 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/02 23:52:36 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*get_extension(char *file)
{
	int		i;
	char	*addr;

	i = 0;
	addr = 0;
	while (file[i])
	{
		if (file[i] == '.')
			addr = &(file[i]);
		i++;
	}
	if (addr)
		return (addr + 1);
	return (addr);
}

int	extension_check(char *file)
{
	char	*extension;

	extension = get_extension(file);
	if (!extension || !(*extension))
		return (1);
	if (ft_strncmp(extension, "rt", 3))
		return (1);
	return (0);
}
