#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_draw_pix(t_fdf *data, t_pt current_p)
{
	int coef;
	int p;
	int color;
	int	x;
	int	y;

	x = (int)(current_p.x * data->zoom) + data->shift_x;
    y = (int)(current_p.y * data->zoom) + data->shift_y;
	int pixel_size = 3;
    int x_offset = -pixel_size / 2;
	p = 0;
	color = 0x007FF100;
	if (current_p.z > 0)
		color = 0x00219CFF;
    while (x_offset <= pixel_size / 2) 
	{
       	int y_offset = -pixel_size / 2;
    	while (y_offset <= pixel_size / 2) 
		{
           	my_mlx_pixel_put(data->img, x + x_offset, y + y_offset, color);
           	y_offset++;
        }
        x_offset++;
    }
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
			ft_draw_pix(data, data->z_matrix[line][col]);
			col++;
		}
		line++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
}

