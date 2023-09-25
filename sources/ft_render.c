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
			my_mlx_pixel_put(data->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	render_txt(t_fdf *data, int intfordisplay, char *txt, char *subtxt)
{
	char	*inttochar;
	int		posx;
	int		cr;
	int		lentxt;

	lentxt = ft_strlen(txt);
	posx = 100;
	cr = 0xFFFFFF;
	if ((ft_strncmp(txt, "Profondeur: ", lentxt) == 0))
		posx = 200;
	if ((ft_strncmp(txt, "Angle: ", lentxt) == 0))
		posx = 300;
	if ((ft_strncmp(txt, "Shift X: ", lentxt) == 0))
		posx = 400;
	if ((ft_strncmp(txt, "Shift Y: ", lentxt) == 0))
		posx = 500;
	inttochar = ft_itoa(intfordisplay);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, posx, cr, txt);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, posx + 20, cr, inttochar);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, posx + 35, cr, subtxt);
	free(inttochar);
}

void	render_gui(t_fdf *data)
{
	render_txt(data, data->zoom, "Zoom: ", "+ / - (Pav Num)");
	render_txt(data, data->profondeur, "Profondeur: ", "; / p");
	render_txt(data, data->angle, "Angle: ", "k / l");
	render_txt(data, data->shift_x, "Shift X: ", "<- / ->");
	render_txt(data, data->shift_y, "Shift Y: ", "A / V");
}

void	render(t_fdf *data)
{
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_background(data);
	render_gui(data);
	ft_draw_map(data);
	mlx_do_sync(data->mlx_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->img_ptr, 250, 0);
}
