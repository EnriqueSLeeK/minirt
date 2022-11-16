#include "../../minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len_line;
	int		endian;
} t_img;

void put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img -> addr + (y * img -> len_line + x * (img ->  bpp / 8));
	*(unsigned int*)dst = color;
}

void	shading(int *r, int *g, int *b, float factor)
{
	*r = ((*r >> 16) - (int)((float)(*r >> 16) * factor)) << 16;
	*g = ((*g >> 8) - (int)((float)(*g >> 8) * factor)) << 8;
	*b = *b - (int)((float)*b * factor);
}

int main(void)
{
	t_img	img;
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 500, 500, "hi");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
									&img.len_line, &img.endian);
	float shading_factor = 0.0;
	for (int h = 0; h < 500; h++)
	{
		for (int w = 0;  w < 500; w++)
		{
			float factor_y = (float)h / (float)499;
			float factor_x = (float)w / (float)499;
			int r = (int)(255.999 * factor_y) << 16;
			int g = (int)(255.999 * factor_x) << 8;
			int b = (int)(255.999 / (float)4);
			shading(&r, &g, &b, shading_factor);
			shading_factor = (factor_y + factor_x) / (float)2;
			put_pixel(&img, h, w, r + g + b);
		}
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
