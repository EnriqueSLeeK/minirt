/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:15 by ensebast          #+#    #+#             */
/*   Updated: 2021/08/06 19:20:15 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(string) + 1;
	dup = malloc(len);
	if (dup == 0)
		return (0);
	ft_strlcpy(dup, string, len);
	return (dup);
}
