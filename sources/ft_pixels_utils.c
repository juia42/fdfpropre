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

void	ft_trans_to_isometric(t_pt *pt, int angle)
{
	pt->x = (pt->x - pt->z) * cos(angle);
	pt->y = (pt->y + pt->z) * cos(angle) - pt->z;
}

// La vraie qui fonctionne pas encore
// Trouver l'endroit ou appliquer le calcul.
/*
void	ft_trans_to_isometric(t_pt *pt, int angle)
{
	pt->x = (pt->x - pt->y) * cos(angle);
	pt->y = (pt->x + pt->y) * sin(angle) - pt->z;
}
*/
int		ft_calcul_the_way(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	return (-1);
}
