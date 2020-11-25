#include "rtmath.h"
int rgba_to_int(int r, int g, int b, int a)
{
	return a << 24 | r << 16 | g << 8 | b;
}
/* NORMALIZED COLOR |0 - 1|*/
int vec4_to_int(t_vec4 c)
{
	return (int)(c.a * 255) << 24 | (int)(c.r * 255) << 16 | (int)(c.g * 255) << 8 | (int)(c.b * 255);
}
int main_image(int x, int y, int width, int height)
{
	t_vec4 col;	col.r = 0.0f;	col.g = 0.0f;	col.b = 0.0f;	col.a = 1.0;
	struct s_vec2 uv;
	float aspect = (float)width / (float)height;
	uv.x = (float)x / (float)width;
	uv.y = (float)y / (float)height;
	uv.x -= 0.5f;
	uv.y -= 0.5f;
	uv.y /= aspect;

	float l = sqrt(uv.x * uv.x + uv.y * uv.y);
	if (l < 0.2)
	{
		col.r = 1 - l * 4;
		col.b = 1 - l * 4;
		col.g = 1 - l * 4;
	}
	//return (rgba_to_int(0.5 * 255, 0.1 * 255, 0.1 * 255, 255));
	return(vec4_to_int(col));
}