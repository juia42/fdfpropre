#include "../includes/fdf.h"

void	render_background(t_fdf *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			img_pix_put(data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}

void	render_map(t_fdf *data)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	while (y < data->m_cols)
	{
		x = 0;
		while (x < data->m_lines)
		{
			if (x < data->m_lines - 1)
			{
				ft_printf("x : %d y : %d. \n",x, y);
				ligne_bresen(data, &data->z_matrix[x][y], &data->z_matrix[x + 1][y]);
				//bresenham(x, y, x + 1, y, data);
			}
			if (y < data->m_cols - 1)
			{
				ft_printf("y : %d y : %d. \n",x, y);
				ligne_bresen(data, &data->z_matrix[x][y], &data->z_matrix[x][y + 1]);
				//bresenham(x, y, x, y + 1, data);
			}
			x++;
		}
		y++;
	}
}

int render(t_fdf *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data, 0x000000);
	ft_printf("i'm done rendering the background :0\n");
	render_map(data);
	ft_printf("i'm done rendering map \n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	ft_printf("new frame put to window :)\n");
	return (0);
}