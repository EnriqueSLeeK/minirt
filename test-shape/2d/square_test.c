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

int	dist(int *point, int *center, int half)
{
	int	delta[2];

	delta[0] = point[0] - center[0];
	delta[1] = point[1] - center[1];
	if (delta[0] <= 0)
		delta[0] *= -1;
	if (delta[1] <= 0)
		delta[1] *= -1;
	if (delta[0] <= half && delta[1] <= half)
		return (1);
	return (0);
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

	int p[2];
	int c[2] = {250, 250};
	for (int h = 0; h < 500; h++)
	{
		for (int w = 0;  w < 500; w++)
		{
			p[0] = h;
			p[1] = w;
			if (dist(p, c, 200))
			{
				int r = (int)(255.999 * ((float)h / (float)499)) << 16;
				int g = (int)(255.999 * ((float)w / (float)499)) << 8;
				int b = (int)(255.999 / (float)2);
				put_pixel(&img, h, w, r + g + b);
			}
		}
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
