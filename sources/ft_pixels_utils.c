#include "../includes/fdf.h"

int	ft_calcul_color(int z)
{
	int couleur; 
	int rouge;
	int bleu;
	int	vert;

	couleur= 0x00219CFF;
	rouge = (couleur >> 16) & 0xFF;
	vert = (couleur >> 8) & 0xFF;
	bleu = couleur & 0xFF;
	bleu = bleu * z / 9;
	return ((rouge << 16) | (vert << 8) | bleu);
}
// La tienne qui fait un resultat drole
/*
void	ft_trans_to_isometric(t_pt *pt, int angle)
{
	pt->x = pt->x - pt->z * cos(angle);
	pt->y = pt->y + pt->z * cos(angle) - pt->z;
}
*/
// La vraie qui fonctionne pas encore
void	ft_trans_to_isometric(t_pt *pt, int angle)
{
	double	rad_angle = angle * M_PI / 180.0;
	double	temp_x = pt->x;
	pt->x = (temp_x - pt->y) * cos(rad_angle);
	pt->y = (temp_x + pt->y) * sin(rad_angle) - pt->z;
}

int		ft_calcul_the_way(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	return (-1);
}
