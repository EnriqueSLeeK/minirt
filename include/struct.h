/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:33:59 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/28 00:19:05 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_ray t_ray;
typedef struct s_elem t_elem;
typedef struct s_intersect t_intersect;

typedef struct	s_matrix
{
	double	m[4][4];
	int		size;
} t_matrix;

typedef struct	s_tuple
{
	double	tup[4];
} t_tuple;

typedef struct s_color {
	double	tup[3];
} t_color;

// Structure ambient light
typedef struct s_ambient
{
	double				light_ratio;
	t_color				color;
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
// Linked list
typedef struct	s_intersect
{
	t_elem		*elem;
	double		t;
} t_intersect;

typedef struct	s_intersect_list
{
	t_intersect	*elem_inter;
	int			size;
	int			n;
} t_intersect_list;

// Structure of planes and entities
// Structure camera
typedef struct s_camera
{
	t_matrix			inv_transform;
	t_matrix			transform;
	t_tuple				norm_vec;
	t_tuple				coord;
	double				half_height;
	double				half_width;
	double				pixel_size;
	double				fov;
} t_camera;

// Structure light
typedef struct s_light
{
	t_tuple				coord;
	t_color				color;
	double				light_ratio;
} t_light;

// mlx
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	t_img	img_inf;
} t_mlx;

typedef struct s_material
{
	t_color		*color;
	t_ambient	*ambient;
	double		specular;
	double		diffuse;
	double		shininess;
} t_material;

typedef struct s_elem
{
	char				type[3];
	t_color				color;
	t_tuple				coord;
	t_tuple				norm_vec;
	t_matrix			transform;
	t_matrix			inv_transform;
	t_matrix			inv_transform_transpose;
	t_material			material;
	double				diameter;
	double				height;
	void				(*intersect)(struct s_elem *, t_ray *, t_intersect_list *);
} t_elem;

// List of elements
// Quant index:
// 0 -> elements
// 1 -> light
// 2 -> ambient
// 3 -> camera
typedef struct s_elements
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
typedef struct s_ray
{
	t_tuple	orig;
	t_tuple	dir;
} t_ray;

// discri = discriminant
typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	discri;
} t_bhaskara;

// A structure to encapsulate useful info
typedef struct s_computation {
	t_elem	*elem;
	t_tuple	position;
	t_tuple	normalv;
	t_tuple	eyev;
	t_tuple	over_point;
	double	t;
	int		inside;
} t_computation;

typedef struct s_hit_elem
{
	double	t;
	t_elem	*elem;
} t_hit_elem;

#endif
