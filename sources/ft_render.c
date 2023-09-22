#include "../includes/fdf.h"

void	render_background(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			my_mlx_pixel_put(data->img, x, y, 0x00032276);
			x++;
		}
		y++;
	}
}
int render(t_fdf *data)
{
	render_background(data);
	ft_draw_map(data);
	mlx_do_sync(data->mlx_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}