#include "../includes/fdf.h"

int	ft_calcul_color(int z,int color)
{
	int couleur; 
	int rouge;
	int bleu;
	int	vert;

	color = color;
	if (z > 0)
	{	
		color = 0x00B0F2B6;
		couleur = color;
		rouge = (couleur >> 16) & 0xFF;
		vert = (couleur >> 8) & 0xFF;
		bleu = couleur & 0xFF;
		bleu = bleu * z / 9;
		color = ((rouge << 16) | (vert << 8) | bleu); 
	}	
	return (color);
}
/*
void ft_trans_to_isometric(t_fdf *data, t_pt *pt, float angle, int profondeur) {
    double angleRadians = angle * M_PI / 180.0;
    int x = pt->x - (data->m_lines / 2);
    int y = pt->y - (data->m_cols / 2);
    pt->x = (data->m_lines / 2) + (int)(x * cos(angleRadians) - y * sin(angleRadians));
    pt->y = (data->m_cols / 2) + (int)(x * sin(angleRadians) + y * cos(angleRadians));
}
*/

void	ft_trans_to_isometric(t_fdf *data, t_pt *pt, float angle, int profondeur)
{
	(void*)data;
	double	rad_angle = angle * M_PI / 180.0;
	double	temp_x = pt->x;
	pt->x = temp_x - pt->y * cos(rad_angle);
	pt->y = temp_x + pt->y * sin(rad_angle) - (pt->z * profondeur);
}

/*
void	ft_trans_to_isometric(t_fdf *data, t_pt *pt, int angle, int profondeur)
{
	double	rad_angle = angle * M_PI / 180.0;
	double	rad_2 = (angle * 2) * M_PI / 180.0;
	double	temp_x = pt->x;
	pt->x = cos(rad_angle) * (pt->y - data->m_lines / 2) 
			- cos(rad_angle) * (pt->x - data->m_cols / 2);
	pt->y = -pt->z * cos(rad_2) * 2 
			+ sin(rad_angle) * (pt->x - data->m_lines / 2)
			+ sin(rad_angle) * (pt->y - data->m_cols / 2);
}
*/
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
	int err2;
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
