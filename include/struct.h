/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:33:59 by ensebast          #+#    #+#             */
/*   Updated: 2022/10/24 13:38:22 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// Structure of planes and entities
typedef struct s_elem
{
	char				type[3];
	double				coord[4];
	double				color[3];
	double				norm_vec[4];
	double				diameter;
	double				height;
	void				(*create_entity)(void *ptr);
} t_elem;

// Structure camera
typedef struct s_camera
{
	double				norm_vec[4];
	double				coord[4];
	double				imageAspectRatio;
	double				scale;
	double				fov;
} t_camera;

// Structure light
typedef struct s_light
{
	double				light_ratio;
	double				coord[4];
	double				color[3];
} t_light;

// Structure ambient light
typedef struct s_ambient
{
	double				light_ratio;
	double				color[3];
} t_ambient;

// Image structure
typedef struct	s_img
{
	char	*addr;
	int		bpp;
	int		len_line;
	int		endian;
} t_img;

// mlx
typedef struct s_mlx {
	void	*mlx;
	void	*img;
	void	*win;
	t_img	img_inf;
} t_mlx;

// List of elements
// Quant index:
// 0 -> elements
// 1 -> camera
// 2 -> light
// 3 -> ambient
typedef struct	s_elements
{
	int			quant[4];
	t_elem		*elem;
	t_light		*light;
	t_ambient	*ambient;
	t_camera	*camera;
	t_mlx		mlx_inf;
} t_list_elem;

#endif
