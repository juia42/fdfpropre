#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_tracer_ligne(t_fdf *data, t_pt pixel1, t_pt pixel2)
{
    t_pt d;
    t_pt s;
	int color;
	int err;
	int err2;
	int maxhuba;

	s = ft_calcul_the_way(pixel1,pixel2);
    d = ft_calculabs(pixel1,pixel2);
	err = 0;
	maxhuba = d.x + d.y;
	color = ft_calcul_color(pixel2.z, pixel2.color);
    while (maxhuba--)
    {
        if (pixel1.x >= 0 && pixel1.x < WIN_W  && pixel1.y >= 0 && pixel1.y < WIN_H)
			my_mlx_pixel_put(data->img, pixel1.x, pixel1.y, color);
        if (pixel1.x == pixel2.x && pixel1.y == pixel2.y)
            break;
		ft_gesterror(&err, d, s, &pixel1);
    }
}

// Deplace gauche droite haut bas par rapport a l'ecran
void ft_prepare_ligne(t_fdf *data, t_pt pixel1, t_pt pixel2)
{
	pixel1.x *= data->zoom;
    pixel1.y *= data->zoom;
    pixel2.x *= data->zoom;
    pixel2.y *= data->zoom;
    ft_trans_to_isometric(&pixel1, data->angle, data->profondeur); // Utilisez l'angle isométrique correct ici
    ft_trans_to_isometric(&pixel2, data->angle, data->profondeur); // Utilisez l'angle isométrique correct ici
    pixel1.x += data->shift_x;
    pixel1.y += data->shift_y;
    pixel2.x += data->shift_x;
    pixel2.y += data->shift_y;
    ft_tracer_ligne(data, pixel1, pixel2);
}

// Deplace gauche droite haut bas par rapport aux cotes de la map.
/*
void ft_prepare_ligne(t_fdf *data, t_pt pixel1, t_pt pixel2)
{
    pixel1.x = (int)(pixel1.x * data->zoom) + data->shift_x;
    pixel1.y = (int)(pixel1.y * data->zoom) + data->shift_y;
    pixel2.x = (int)(pixel2.x * data->zoom) + data->shift_x;
    pixel2.y = (int)(pixel2.y * data->zoom) + data->shift_y;
	ft_trans_to_isometric(&pixel1, data->angle);
	ft_trans_to_isometric(&pixel2, data->angle);
	ft_tracer_ligne(data, pixel1, pixel2);
}
*/
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

