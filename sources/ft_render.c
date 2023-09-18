#include "../includes/fdf.h"

void	render_background(t_fdf *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->m_height)
	{
		x = 0;
		while (x < data->m_width)
		{
			img_pix_put(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_map(t_fdf *data)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	ft_printf("dans render map\n");
	while (y < data->m_width)
	{
		x = 0;
		while (x < data->m_height)
		{
			if (x < data->m_height - 1)
			{
				ft_printf("x : %d y : %d. \n",x, y);
				ligne_bresen(data, &data->z_matrix[x][y], &data->z_matrix[x + 1][y]);

				//bresenham(x, y, x + 1, y, data);
			}
			if (y < data->m_width - 1)
			{
				ft_printf("y : %d y : %d. \n",x, y);
				ligne_bresen(data, &data->z_matrix[x][y], &data->z_matrix[x][y + 1]);
				//ft_printf("Y - x = %i\ty = %i\n", x, y);
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
	render_map(data);
	ft_printf("apres map \n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	return (0);
}