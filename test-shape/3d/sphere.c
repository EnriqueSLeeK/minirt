#include "../../../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len_line;
	int		endian;
} t_img;


int check_hit(double *coord);

double	vec_square_len(double *v)
{
	if (v == 0)
		return (-1);
	return (v[0] * v[0] +
			v[1] * v[1] +
			v[2] * v[2]);
}

double	vec_len(double *v)
{
	if (v == 0)
		return (-1);
	return (sqrt(vec_square_len(v)));
}

double	*normalize(double *v)
{
	double  len;
	double	inv_len;
	double	*buff = malloc(3 * sizeof(double));

	len = vec_len(v);
	if (len > 0)
	{
		inv_len = 1 / len;
		buff[0] = v[0] * inv_len;
		buff[1] = v[1] * inv_len;
		buff[2] = v[2] * inv_len;
	}
	return (buff);
}

double	dot_prod(double *v_f, double *v_s)
{
	if (v_f == 0 && v_s == 0)
		return (-1);
	return (v_f[0] * v_s[0] +
			v_f[1] * v_s[1] +
			v_f[2] * v_s[2]);
}

void put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img -> addr + (y * img -> len_line + x * (img ->  bpp / 8));
	*(unsigned int*)dst = color;
}

void render(int width, int height, t_img *img)
{
	double coord[2];
	int    color;
	double ratio;

	ratio = (double) width / (double) height;
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			coord[0] = (ratio * ((double)x / ((double)width) * 2.0)) - 1.0;
			coord[1] = (ratio * ((double)y / ((double)height) * 2.0)) - 1.0;
			color = check_hit(coord);
			put_pixel(img, x, y, color);
		}
	}
}

double *do_calc(double *origin, double *raydir, double root_one)
{
	double *buff = malloc(3 * sizeof(double));

	for (int i = 0; i < 3; i++)
	{
		raydir[i] *= root_one;
		buff[i] = origin[i] + raydir[i];
	}
	return (buff);
}

double *flip_sign(double *vec)
{
	for (int i = 0; i < 3; i++)
		vec[i] *= -1;
	return (vec);
}

void shading(int *color, double factor)
{
	int r = (int)(255.0 * factor);
	int g = (int)(255.0 * factor);
	int b = (int)(255.0 * factor);

	*color = r << 16 | g << 8 | b;
}

int check_hit(double *coord)
{
	int	color = 0;
	double origin[3] = {0.0, 0.0, 1.0};
	double raydir[3] = {coord[0], coord[1], -1};
	double radius = 0.3;

	double a = dot_prod(raydir, raydir);
	double b = 2.0 * dot_prod(origin, raydir);
	double c = dot_prod(origin, origin) - (radius * radius);

	double discri = (b * b) - (4.0 * a * c);
	if (discri < 0)
		return (0);

	double root_one = (- b - sqrt(discri)) / (2.0 * a);
	double root_two = (- b + sqrt(discri)) / (2.0 * a);

	double *hitpoint = do_calc(origin, raydir, root_one);
	double *normal = normalize(hitpoint);

	double tmp[3] = {-1, -1, -1};
	double *light_dir = normalize(tmp);
	double light_intesity = fmax(dot_prod(normal, flip_sign(light_dir)), 0.0);

	free(normal);
	free(hitpoint);
	free(light_dir);

	shading(&color, light_intesity);
	return color;
}

int main(void)
{
	t_img	img;
	void	*mlx;
	void	*mlx_window;

	int 	width = 500;
	int 	height = 500;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, width, height, "hi");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
									&img.len_line, &img.endian);

	render(width, height, &img);

	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
