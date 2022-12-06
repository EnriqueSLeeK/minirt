#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "earth.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_destroy_image(mlx, img);
	mlx_destroy_display(mlx);
	free(mlx);
}
