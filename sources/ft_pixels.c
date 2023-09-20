#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void tracer_ligne(t_image *img, int x1, int y1, int x2, int y2, int color, int zoom)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int err2;

    while (1)
    {
        if (x1 >= 0 && x1 < WIN_W  && y1 >= 0 && y1 < WIN_H)
			my_mlx_pixel_put(img, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void ft_draw_line_between_pixels(t_fdf *data, t_pt pixel1, t_pt pixel2)
{
    int x1 = (int)(pixel1.x * data->zoom) + data->shift_x;
    int y1 = (int)(pixel1.y * data->zoom) + data->shift_y;
    int x2 = (int)(pixel2.x * data->zoom) + data->shift_x;
    int y2 = (int)(pixel2.y * data->zoom) + data->shift_y;
	int color = 0x557FF100;
	if (pixel2.z > 0)
		color = ft_calcul_color(pixel2.z);
    tracer_ligne(data->img, x1, y1, x2, y2, color, data->zoom);
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
                ft_draw_line_between_pixels(data, data->z_matrix[line][col], data->z_matrix[line][col + 1]);
            }

            if (line < data->m_lines - 1) {
                ft_draw_line_between_pixels(data, data->z_matrix[line][col], data->z_matrix[line + 1][col]);
            }
			col++;
		}
		line++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}

