#include <stdio.h>
#include <math.h>

int	main(void)
{
	float	rot_x;
	float	rot_y;
	scanf("%f", &rot_x);
	scanf("%f", &rot_y);
	rot_x = rot_x * ((double)M_PI / 180.0);
	rot_y = rot_y * ((double)M_PI / 180.0);
	printf("%f %f %f\n", cos(rot_x) * sin(rot_y),
			sin(rot_x) * sin(rot_y),
			cos(rot_y));
}
