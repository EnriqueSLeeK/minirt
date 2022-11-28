/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:07:16 by ensebast          #+#    #+#             */
/*   Updated: 2022/11/27 23:49:52 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FUNCTIONS_H
# define FUNCTIONS_H

// CAMERA -----------------------------------------------
void				camera_compute(t_camera *camera, double h_size, double v_size);
t_tuple				get_up(t_tuple orientation);

// File Checker -----------------------------------------
// Line check
int					check_count_line(char *line, int *count);

// Util
int					next_segment(char *line);
int					find_char(char *line, char c);

// Checker functions
int					check_int_len(char *num);
int					check_float(char *segment);
int					check_int(char *segment);

// Scenario
int					check_light(char *line);
int					check_camera(char *line);
int					check_ambient_light(char *line);

// Format
int					check_plane(char *line);
int					check_sphere(char *line);
int					check_cylinder(char *line);

// Micro regex
int					match_exp(char *regexp, char *text);

// Move the pointer and call a checking function
int					check_and_move(char **line, int nelem,
						int (*check)(char *));

// Check extension
int					extension_check(char *file);

// General checker
int					check_segment(char *segment, int cycle, int limit, int (*checker)(char *));

// Parse ------------------------------------------------
// Line parse
int					parse_line(char *, t_list_elem *);

// Util
int					next_segment(char *line);
int					find_char(char *line, char c);

// Scenario
int					parse_light(char *line, t_light **elem);
int					parse_camera(char *line, t_camera *elem);
int					parse_ambient_light(char *line, t_ambient *elem);

// Format
int					parse_plane(char *line, t_elem **elem);
int					parse_sphere(char *line, t_elem **elem);
int					parse_cylinder(char *line, t_elem **elem);

// Micro regex
int					match_exp(char *regexp, char *text);

// Move the pointer and call a parse function
int					parse_and_move(char **line, int nelem, void *buff,
						void (*parse)(void **, char *));

// General checker
int					parse_segment(char *segment, int cycle, void *buff,
						void (*parse)(void **, char *));

// Value range check
int					range_double_check(double *val, int n,
			double lower, double upper);

int					range_int_check(int *val, int n,
			int lower, int upper);

// Convert char to int
int					str_to_int(char *);
double				str_to_double(char *);

// Parse numbers
void				parse_float(void **buff, char *d_str);
void				parse_color(void **buff, char *i_str);
void				parse_int(void **buff, char *i_str);

// Math_op ----------------------------------------------

// Calculate the normal vector
t_tuple				normal_at(t_elem *elem, t_tuple w_p);

// * Color ---------
t_color				cmult(t_color c_one, t_color c_two);
t_color				cadd(t_color c_one, t_color c_two);
t_color				csub(t_color c_one, t_color c_two);
t_color				csmult(t_color color, double f);

// Create color
t_color				create_c(double r, double g, double b);

// * Matrix -------
// Matrix creation
t_matrix			create_m(int dim);
t_matrix			create_identity_m(void);

// Util function
void				matrix_cpy(t_matrix *m_d, t_matrix *m_s);
void				identity_m(t_matrix *matrix);

// Determinant calc
t_matrix			submatrix(t_matrix matrix, int r, int c);
double				cof(t_matrix matrix, int r, int c);
double				det(t_matrix matrix);

// Matrix operations
t_matrix			inverse_m(t_matrix m);
t_tuple				m_mult_t(t_matrix matrix, t_tuple tuple);
t_matrix			m_mult(t_matrix matrix_p, t_matrix matrix_s);
t_matrix			transpose_m(t_matrix matrix);
int					matrix_cmp(t_matrix matrix_p, t_matrix matrix_s);

// Transformation
t_matrix			translation(double x, double y, double z);
t_matrix			scaling(double x, double y, double z);
t_matrix			rotation_x(double rad);
t_matrix			rotation_y(double rad);
t_matrix			rotation_z(double rad);

// Set transform
void				set_transform(t_elem *elem, t_matrix transform);
void				set_camera_transform(t_camera *elem, t_matrix transform);
t_matrix			view_transform(t_tuple from, t_tuple to, t_tuple up);

// Tuple op -------
// Composite op
t_tuple				tadd(t_tuple t_one, t_tuple t_two);
t_tuple				tsub(t_tuple t_one, t_tuple t_two);
t_tuple				tcross(t_tuple t_one, t_tuple t_two);
double				tdot(t_tuple t_one, t_tuple t_two);

// Simple op
double				tmag(t_tuple tup);
t_tuple				tnorm(t_tuple tup);
t_tuple				tneg(t_tuple tup);
t_tuple				tsdiv(t_tuple tup, double f);
t_tuple				tsmult(t_tuple tup, double f);

// Vector reflection
t_tuple				treflect(t_tuple v, t_tuple n);

// Tuple init
t_tuple				create_t(double xr, double yg, double zb, double w);
t_tuple				vector(double x, double y, double z);
t_tuple				point(double x, double y, double z);

// Raytrace ---------------------------------------------
// Intersection list ----
void				list_cpy(t_intersect *dst, t_intersect *src, int n);
void				add_intersect(t_intersect_list *ptr, t_elem *elem, double t);
void				resize_list(t_intersect_list *list);

t_intersect_list	*create_list(int size);
t_intersect			*hit(t_intersect_list *list);

// Computation contructor
t_computation		prepare_computation(t_intersect *inter, t_ray *ray);


// ray shooting and hit in general
void				raytrace(t_list_elem *elem_list);
void				start_raytrace(t_list_elem *elem_list);
t_intersect			*ray_shoot(t_list_elem *list_elem, t_ray *ray);

// Intersection functions
// Sphere:
void				intersect_s(t_elem *elem, t_ray *ray, t_intersect_list *i_list);
// Plane:
void				intersect_pl(t_elem *elem, t_ray *ray, t_intersect_list *i_list);

// Light ------------------------------------------------
t_material			material(t_color *color, t_ambient *ambient);
t_color				lighting(t_material *m, t_light *light, t_computation *info, int in_shadow);
int					is_shadowed(t_list_elem *world, t_tuple point);

// Ray --------------------------------------------------
// Calculate position
t_tuple				position(t_ray *ray, double t);
// Transform ray using a transformation matrix
t_ray				transform_ray(t_ray *ray, t_matrix *transform);
// Create a ray based on the pixel and camera
t_ray				ray_for_pixel(t_camera *camera, double px, double py);

// MLX --------------------------------------------------
// Mlx preparation
int					mlx_prepare(t_mlx *);

// Key event hook
int					key_hook(int keycode, void *param);
int					mlx_key_event(int keycode, void *param);

// Free everything and exit
int					close_prog(void *param);

// Start the loop and set the image to the window
void				mlx_start(t_list_elem *elem_list);

// Put a pixel
void				put_pixel(t_img *img, int x, int y, int color);

// Util -------------------------------------------------
// Memory alloc
int					alloc_mem(t_list_elem *buff, int *count);
void				dealloc_mem(t_list_elem *buff);
void				dealloc_list(t_intersect *inter);

// Aux functions
char				*get_line(int fd);
int					deg_to_rad(double *fov);
int					make_color(double r, double g, double b);
int					cmp_float(double f, double s);
#endif
