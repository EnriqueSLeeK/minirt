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

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			coord[0] = ((double)x / ((double)width) * 2.0) - 1.0;
			coord[1] = ((double)y / ((double)height) * 2.0) - 1.0;
		}
	}
}

int main(void)
{
	t_img	img;
	void	*mlx;
	void	*mlx_window;

	int 	width = 500;
	int 	height = 400;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, width, height, "hi");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
									&img.len_line, &img.endian);


	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
