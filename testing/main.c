#include <mlx.h>
#include <ft_printf.h>

typedef	struct	s_win_info
{
	void 	*mlx_ptr;
	void	*mlx_win;
}				t_win_info;

void mousePos(int mouse, int x, int y, void *params)
{
	ft_printf("(%d, %d)\n", x, y);
	mlx_pixel_put(((t_win_info *)params)->mlx_ptr, ((t_win_info *)params)->mlx_win, x, y, 0x00FF0000);
}

void close_window(int keycode, void *params)
{
	ft_printf("Pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(((t_win_info *)params)->mlx_ptr, ((t_win_info *)params)->mlx_win);
		exit(0);
	}
}

int     main(void)
{
	t_win_info vars;

    vars.mlx_ptr = mlx_init();
    vars.mlx_win = mlx_new_window(vars.mlx_ptr, 800, 600, "Hello world!");

	ft_printf("Hola");

	mlx_mouse_hook(vars.mlx_win, mousePos, (void *)&vars);
	mlx_key_hook(vars.mlx_win, close_window, (void *)&vars);

    mlx_loop(vars.mlx_ptr);
}    