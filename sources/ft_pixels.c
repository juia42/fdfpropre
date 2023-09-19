#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_draw_map(t_fdf *data)
{
	int	line;
	int	col;
	int color;

	line = 0;
	while(line < data->m_lines)
	{
		col = 0;
		while(col < data->m_cols)
		{
			color = 0x007FF100;
			if (data->z_matrix[line][col].z > 0)
				color = 0x00219CFF;
			my_mlx_pixel_put(data->img, data->z_matrix[line][col].x +100, data->z_matrix[line][col].y +100, color);
			col++;
		}
		line++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}