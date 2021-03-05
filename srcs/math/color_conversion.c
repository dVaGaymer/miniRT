#include "../../includes/minirt.h"

/* Must be char¿ */
int rgba_to_int(int r, int g, int b, int a)
{
	return a << 24 | r << 16 | g << 8 | b;
}

/* NORMALIZED COLOR |0 - 1|*/
int vec4_to_int(t_vec4 c)
{
	return (int)(c.a * 255) << 24 | (int)(c.r * 255) << 16 | (int)(c.g * 255) << 8 | (int)(c.b * 255);
}