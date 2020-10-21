#include <mlx.h>
#include <ft_printf.h>

typedef	struct	s_win_info
{
	void 	*mlx_ptr;
	void	*mlx_win;
}				t_win_info;

struct s_canvas_info
{
	void	*canvas;
	char	*addr;
	int		width;
	int		height;
	int 	bpp;
	int		size_line;
	int		endian;
};

void close_window(int keycode, void *params)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(((t_win_info *)params)->mlx_ptr, ((t_win_info *)params)->mlx_win);
		ft_printf("End");
		exit(0);
	}
}

struct s_vec3
{
	float x;
	float y;
	float z;
};

struct s_triangle
{
	struct s_vec3 p0;
	struct s_vec3 p1;
	struct s_vec3 p2;
};

struct s_ray
{
	
};

void fill_pixel(struct s_canvas_info canvas_info, int x, int y, int color)
{
	char *dst;
	dst = canvas_info.addr + canvas_info.size_line * y + x * (canvas_info.bpp / 8);
	*(unsigned int *)dst = color;
}

int rgba_to_int(int r, int g, int b, int a)
{
	return a << 24 | r << 16 | g << 8 | b;
}

int     main(void)
{
	struct s_win_info win_info;
	struct s_canvas_info canvas_info;

	//Setup
	canvas_info.width = 800;
	canvas_info.height = 600;
    win_info.mlx_ptr = mlx_init();
    win_info.mlx_win = mlx_new_window(win_info.mlx_ptr, canvas_info.width, canvas_info.height, "Hello world!");


	canvas_info.canvas = mlx_new_image(win_info.mlx_ptr, canvas_info.width, canvas_info.height);
	canvas_info.addr = mlx_get_data_addr(canvas_info.canvas, &canvas_info.bpp, &canvas_info.size_line, &canvas_info.endian);

	//Hook events
	mlx_key_hook(win_info.mlx_win, close_window, (void *)&win_info);

	//Draw on canvas
	int color, r, g, b;
	for (int y = 0; y < canvas_info.height; y++)
	{
		for (int x = 0; x < canvas_info.width; x++)
		{
			r = (255 * (1 - (float)y / (float)canvas_info.height));
			g = (255 * ((float)y / (float)canvas_info.height));
			b =	(255 * ((float)x / (float)canvas_info.width));
			
			color = rgba_to_int(r, g, b, 0);
			fill_pixel(canvas_info, x, y, mlx_get_color_value(win_info.mlx_ptr, color));
		}
	}
	ft_printf("Img filled!\n");

	//Add canvas to window
	mlx_put_image_to_window(win_info.mlx_ptr, win_info.mlx_win, canvas_info.canvas, 0, 0);

    mlx_loop(win_info.mlx_ptr);
}    