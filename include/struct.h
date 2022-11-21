/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:33:59 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/21 02:52:14 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

struct s_elem;
typedef struct s_elem t_elem;

struct s_ray;
typedef struct s_ray t_ray;

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

// t = intersection points
// elem = object in question
typedef struct	s_intersect
{
	t_elem				*elem;
	double				t;
} t_intersect;

// Possible to do:
//   -> Implement a sorting algorithm if necessary
// Dynamic array base structure
typedef struct	s_intersect_list
{
	t_intersect	*elem_inter;
	int			size;
	int			n;
} t_intersect_list;

// Structure of planes and entities
typedef struct s_elem
{
	char				type[3];
	double				coord[4];
	double				color[3];
	double				norm_vec[4];
	double				**trasf[4][4];
	double				diameter;
	double				height;
	void				(*intersect)(struct s_elem *elem, t_ray *ray, t_intersect_list *list);
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
	int					quant[4];
	t_elem				*elem;
	t_light				*light;
	t_camera			*camera;
	t_ambient			*ambient;
	t_intersect_list	*intersect_l;
	t_mlx				mlx_inf;
} t_list_elem;

// orig = origin of the ray
// dir = direction of the ray
typedef struct	s_ray
{
	double	*orig;
	double	*dir;
} t_ray;

// discri = discriminant
typedef struct	s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	discri;
} t_bhaskara;

#endif
