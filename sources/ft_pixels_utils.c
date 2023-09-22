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
		couleur= color;
		rouge = (couleur >> 16) & 0xFF;
		vert = (couleur >> 8) & 0xFF;
		bleu = couleur & 0xFF;
		bleu = bleu * z / 9;
		color = ((rouge << 16) | (vert << 8) | bleu); 
	}	
	return (color);
}
// La tienne qui fait un resultat drole
/*
void	ft_trans_to_isometric(t_pt *pt, int angle)
{
	pt->x = pt->x - pt->z * cos(angle);
	pt->y = pt->y + pt->z * cos(angle) - pt->z;
}
*/
void	ft_trans_to_isometric(t_pt *pt, int angle, int profondeur)
{
	double	rad_angle = angle * M_PI / 180.0;
	double	temp_x = pt->x;
	pt->x = (temp_x - pt->y) * cos(rad_angle);
	pt->y = (temp_x + pt->y) * sin(rad_angle) - (pt->z * profondeur);
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
	int err2;
	int	x;
	int	y;

	x = pixel1->x;
	y = pixel1->y;

	err2 = 2 * (*err);
    if (err2 > -d.y)
    {
    	*err -= d.y;
    	pixel1->x = x + (int)s.x;
    }
    if (err2 < d.x)
    {
    	*err += d.x;
    	pixel1->y = y + (int)s.y;
    }
}
