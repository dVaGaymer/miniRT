#include "../includes/minirt.h"
#include <libft.h>
#include <mlx.h>

/* Hook functions */
void	close_window(int keycode, void *params)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(((t_win_info *)params)->mlx_ptr, ((t_win_info *)params)->mlx_win);
		ft_printf("End");
		exit(0);
	}
}

void	mlx_setup(t_win_info *win_info, t_canvas_info *canvas_info)
{
	canvas_info->width = 800;
	canvas_info->height = 600;
    win_info->mlx_ptr = mlx_init();
    win_info->mlx_win = mlx_new_window(win_info->mlx_ptr, canvas_info->width, canvas_info->height, "MiniRT");
	canvas_info->canvas = mlx_new_image(win_info->mlx_ptr, canvas_info->width, canvas_info->height);
	canvas_info->addr = mlx_get_data_addr(canvas_info->canvas, &(canvas_info->bpp), &(canvas_info->size_line), &(canvas_info->endian));
	//hooks
	mlx_key_hook(win_info->mlx_win, close_window, (void *)win_info);
}