/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:58:08 by ensebast          #+#    #+#             */
/*   Updated: 2022/12/03 18:30:10 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	basic_check(int argc, char **argv)
{
	if (argc != 2 || extension_check(*(argv + 1)))
		return (1);
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
	if (count[1] < 2 && count[2] < 2 && count[3] < 2)
		return (0);
	return (1);
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
	if (basic_check(argc, argv)
		|| check_count_lines(list_elem.quant, argv[1])
		|| alloc_mem(&list_elem, list_elem.quant)
		|| mlx_prepare(&list_elem.mlx_inf))
	{
		write(2, "Error: Error at checking or alloc memory\n", 6);
		return (1);
	}
	if (parse_lines(*(argv + 1), &list_elem))
	{
		write(2, "Error: Error at parsing\n", 24);
		dealloc_all_mem(&list_elem, &list_elem.mlx_inf);
		return (1);
	}
	set_material(&list_elem);
	start_raytrace(&list_elem);
	mlx_start(&list_elem);
	return (0);
}
