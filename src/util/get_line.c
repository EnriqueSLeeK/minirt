/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:55:22 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/06 21:12:06 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*write_buff(char *buff, int fd, int limit);
static void	ft_strcpy(char *dst, char *src);
static char	*ft_realloc(char *old);

char	*get_line(int fd)
{
	char	*buff;

	buff = malloc((sizeof(char) * 20) + 1);
	if (buff == 0)
		return (0);
	ft_memset(buff, 0, 20);
	buff[20] = 0;
	buff = write_buff(buff, fd, 19);
	return (buff);
}

static void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
}

static char	*ft_realloc(char *old)
{
	char	*new;
	int		len;

	len = ft_strlen(old);
	new = malloc((len * 2) + 1);
	ft_memset(new, 0, len * 2);
	new[len * 2] = 0;
	ft_strcpy(new, old);
	free(old);
	return (new);
}

static char	*write_buff(char *buff, int fd, int limit)
{
	char	c;
	int		i;
	int		read_byte;

	i = 0;
	c = 0;
	read_byte = read(fd, &c, 1);
	while (read_byte && read_byte != -1 && c != '\n')
	{
		if (i > limit)
		{
			buff = ft_realloc(buff);
			limit *= 2;
		}
		buff[i] = c;
		read_byte = read(fd, &c, 1);
		i += 1;
	}
	if (read_byte == 0 || read_byte == -1)
	{
		free(buff);
		buff = 0;
		return (0);
	}
	return (buff);
}
