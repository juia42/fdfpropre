#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_tracer_ligne(t_fdf *data, t_pt pixel1, t_pt pixel2)
{
    int dx = abs(pixel2.x - pixel1.x);
    int dy = abs(pixel2.y - pixel1.y);
    int sx = ft_calcul_the_way(pixel1.x,pixel2.x);
    int sy = ft_calcul_the_way(pixel1.y,pixel2.y);
    int err = dx - dy;
    int err2;
	int color = 0x557FF100;
	if (pixel2.z > 0)
		color = ft_calcul_color(pixel2.z);
    while (1)
    {
        if (pixel1.x >= 0 && pixel1.x < WIN_W  && pixel1.y >= 0 && pixel1.y < WIN_H)
			my_mlx_pixel_put(data->img, pixel1.x, pixel1.y, color);
        if (pixel1.x == pixel2.x && pixel1.y == pixel2.y)
            break;
        err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            pixel1.x += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            pixel1.y += sy;
        }
    }
}

void ft_prepare_ligne(t_fdf *data, t_pt pixel1, t_pt pixel2)
{
    pixel1.x = (int)(pixel1.x * data->zoom) + data->shift_x;
    pixel1.y = (int)(pixel1.y * data->zoom) + data->shift_y;
    pixel2.x = (int)(pixel2.x * data->zoom) + data->shift_x;
    pixel2.y = (int)(pixel2.y * data->zoom) + data->shift_y;
	ft_trans_to_isometric(&pixel1, 0.8);
	ft_trans_to_isometric(&pixel2, 0.8);
	ft_tracer_ligne(data, pixel1, pixel2);
}

void ft_draw_map(t_fdf *data)
{
	int	line;
	int	col;

	line = 0;
	while(line < data->m_lines)
	{
		col = 0;
		while(col < data->m_cols)
		{
            if (col < data->m_cols - 1) {
                ft_prepare_ligne(data, data->z_matrix[line][col], data->z_matrix[line][col + 1]);
            }

            if (line < data->m_lines - 1) {
                ft_prepare_ligne(data, data->z_matrix[line][col], data->z_matrix[line + 1][col]);
            }
			col++;
		}
		line++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}

