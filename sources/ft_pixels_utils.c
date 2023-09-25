#include "../includes/fdf.h"

int	ft_calcul_color(int z, int color, int max_z)
{
	int	newcolor;
	int	rouge;
	int	bleu;
	int	vert;

	if (z > 0)
	{
		if (color == 0)
			newcolor = 0x800080;
		else
			newcolor = color;
		rouge = (newcolor >> 16) & 0xFF;
		vert = (newcolor >> 8) & 0xFF;
		bleu = newcolor & 0xFF;
		bleu = bleu + (255 - bleu) * z / max_z;
		newcolor = ((rouge << 16) | (vert << 8) | bleu);
	}
	else
	{
		if (color == 0)
			newcolor = 0xFF00FF;
		else
			newcolor = color;
	}
	return (newcolor);
}
/*
void	ft_trans_to_isometric(t_fdf *data, t_pt *pt, float angle, int depth)
{
	double	rad_angle;
	double	temp_x;
	double	temp_y;

	rad_angle = angle * M_PI / 180.0;
	temp_x = pt->x - data->ptcenter->x;
	temp_y = pt->y - data->ptcenter->y;
	pt->x = temp_x - temp_y * cos(rad_angle);
	pt->y = temp_x + temp_y * sin(rad_angle) - (pt->z * depth);
}
*/

void	ft_trans_to_isometric(t_fdf *data, t_pt *point, float angle, int depth)
{
	float	x_iso;
	float	y_iso;

	(void)data;
	x_iso = (point->x - point->y) * cos(angle * M_PI / 180);
	y_iso = -point->z + (point->x + point->y) * sin(angle * M_PI / 180);
	point->x = x_iso;
	point->y = y_iso - (point->z * depth);
}

t_pt	ft_calcul_the_way(t_pt p1, t_pt p2)
{
	t_pt	s;

	s.x = -1;
	s.y = -1;
	if (p1.x < p2.x)
		s.x = 1;
	if (p1.y < p2.y)
		s.y = 1;
	return (s);
}

t_pt	ft_calculabs(t_pt p1, t_pt p2)
{
	t_pt	d;

	d.x = abs(p2.x - p1.x);
	d.y = abs(p2.y - p1.y);
	return (d);
}

void	ft_gesterror(int *err, t_pt d, t_pt s, t_pt *pixel1)
{
	int	err2;
	int	x;
	int	y;

	x = pixel1->x;
	y = pixel1->y;
	err2 = 2 * (*err);
	if (err2 > -d.x)
	{
		*err -= d.y;
		pixel1->x = x + (int)s.x;
	}
	if (err2 < d.y)
	{
		*err += d.x;
		pixel1->y = y + (int)s.y;
	}
}
