/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:58:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/20 21:49:45 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	basic_check(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Usage: ./minirt <input file>\n", 29);
		write(2, "Note: The input file must have the rt extension\n", 48);
		return (1);
	}
	if (extension_check(*(argv + 1)))
	{
		write(2, "Bad extension\n", 14);
		return (1);
	}
	return (0);
}

// 1 set ptr
// 0 restore
static void	ptr_restoration(t_list_elem *list_elem, void **restore, int mode)
{
	if (mode)
	{
		restore[0] = list_elem -> elem;
		restore[1] = list_elem -> light;
		restore[2] = list_elem -> ambient;
		restore[3] = list_elem -> camera;
		return ;
	}
	list_elem -> elem = restore[0];
	list_elem -> light = restore[1];
	list_elem -> ambient = restore[2];
	list_elem -> camera = restore[3];
}

static int	parse_lines(char *file, t_list_elem *elem)
{
	void	*restore[4];
	char	*buff;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	ptr_restoration(elem, restore, 1);
	buff = get_line(fd);
	while (buff)
	{
		if (parse_line(buff, elem) == 0)
		{
			ptr_restoration(elem, restore, 0);
			free(buff);
			return (1);
		}
		free(buff);
		buff = get_line(fd);
	}
	close(fd);
	ptr_restoration(elem, restore, 0);
	return (0);
}

static int	check_count_lines(int *count, char *file)
{
	int		fd;
	char	*buff;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	buff = get_line(fd);
	if (buff == 0)
		return (1);
	while (buff)
	{
		if (!check_count_line(buff, count))
		{
			free(buff);
			return (1);
		}
		free(buff);
		buff = get_line(fd);
	}
	close(fd);
	return (0);
}

// 1. Basic checks: extension and arg quant check
// 2. Line check and parse
//	2a. If failure free memory then exit
// 3. Funny rays
// 4. Paint the image
int	main(int argc, char **argv)
{
	t_list_elem	list_elem;

	ft_memset(list_elem.quant, 0, sizeof(int) * 4);
	if (basic_check(argc, argv))
		return (1);
	if (check_count_lines(list_elem.quant, argv[1]))
	{
		write(2, "Error: empty file or bad file\n", 30);
		return (1);
	}
	if (alloc_mem(&list_elem, list_elem.quant)
		|| mlx_prepare(&list_elem.mlx_inf))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (parse_lines(*(argv + 1), &list_elem))
	{
		write(2, "Error\n", 6);
		dealloc_mem(&list_elem);
		return (1);
	}
	raytrace(&list_elem);
	mlx_start(&list_elem);

	// Testing
	dealloc_mem(&list_elem);
	return (0);
}
