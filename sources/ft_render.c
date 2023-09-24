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
void	render_txt(t_fdf *data, int intfordisplay, char *txt, char *subtxt)
{
	char	*inttochar;
	int		posx;

	posx = 100;
	if (txt == "Profondeur: ")
	posx = 200;
	if (txt == "Angle: ")
	posx = 300;
	inttochar = ft_itoa(intfordisplay);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, posx, 0xFFFFFF, txt);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, posx + 20, 0xFFFFFF,	inttochar);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, posx + 35, 0xFFFFFF,	subtxt);
	free(inttochar);
}

int render_gui(t_fdf *data)
{
	render_txt(data, data->zoom, "Zoom: ", "+ / - (Pav Num)");
	render_txt(data, data->profondeur, "Profondeur: ", "; / p");
	render_txt(data, data->angle, "Angle: ", "k / l");
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