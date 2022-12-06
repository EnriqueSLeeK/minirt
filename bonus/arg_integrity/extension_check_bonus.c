/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:53:40 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/04 22:32:09 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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

int	extension_check(char *file, char *target)
{
	int		len;
	char	*extension;

	extension = get_extension(file);
	if (!extension || !(*extension))
		return (1);
	len = ft_strlen(extension);
	if (ft_strncmp(extension, target, len + 1))
		return (1);
	return (0);
}
