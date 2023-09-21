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

void	ft_trans_to_isometric(t_pt pt, int angle)
{
	pt.x = (pt.x - pt.y) * cos(0.8);
	pt.y = (pt.x + pt.y) * sin(0.8) - pt.z;
}

int		ft_calcul_the_way(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	return (0);
}
