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

    mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	render_background(data);
	ft_draw_map(data);
}


/*
Ideally on render we want to :

Clear window ? (Dont know if usefull using images)
Add a backbuffer, another   t_image *backbuffer
Our img will be renamed     t_image *frontbuffer.

Render next frame to backbuffer
Swap backbuffer and frontbuffer
Clear backbuffer (old front) for next frame
Draw map.
*/
