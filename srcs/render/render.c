#include "../../includes/minirt.h"
#include "../../includes/minirt.h"
#include <mlx.h>

void fill_pixel(t_canvas_info *canvas_info, int x, int y, int color)
{
	char *dst;
	dst = canvas_info->addr + canvas_info->size_line * y + x * (canvas_info->bpp / 8);
	*(unsigned int *)dst = color;
}

int shade(int x, int y, int width, int height, t_scene scene)
{
	t_vec4 col;

	col.r = 1.0f;
	col.g = 0.0f;
	col.b = 0.0f;
	col.a = 1.0;
	return(vec4_to_int(col));
}

void	display(t_win_info *win_info, t_canvas_info *canvas_info, t_scene scene)
{
	//Draw on canvas
	int color;
	for (int y = 0; y < canvas_info->height; y++)
		for (int x = 0; x < canvas_info->width; x++)
		{	
			color = shade(x, y, canvas_info->width, canvas_info->height, scene);
			fill_pixel(canvas_info, x, y, mlx_get_color_value(win_info->mlx_ptr, color));
		}
	//Add canvas to window
	mlx_put_image_to_window(win_info->mlx_ptr, win_info->mlx_win, canvas_info->canvas, 0, 0);
}

t_fragment	cast_ray(t_vec3 dir, int depth)
{
	t_fragment frag;
	
	return(frag);
}