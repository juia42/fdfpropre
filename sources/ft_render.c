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
// Faire un rectangle sur le cote gauche de l'ecran,
// Sur lequel afficher les informations liees a la visu.
// Decaler l'image de sa largeur.

int render_gui(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 100, 0xFFFFFF, "Zoom: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 115, 0xFFFFFF, ft_itoa(data->zoom));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 125, 0xFFFFFF, "+ / - (Pav Num)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 200, 0xFFFFFF, "Profondeur: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 215, 0xFFFFFF, ft_itoa(data->profondeur));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 225, 0xFFFFFF, "; / p");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 300, 0xFFFFFF, "Angle: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 315, 0xFFFFFF, ft_itoa(data->angle));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 325, 0xFFFFFF, "k / l");

}


int render(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	render_background(data);
	render_gui(data);
	ft_draw_map(data);
	mlx_do_sync(data->mlx_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 250, 0);
}