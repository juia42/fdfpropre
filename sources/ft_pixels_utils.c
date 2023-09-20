#include "../includes/fdf.h"

int	ft_calcul_color(int z)
{
int couleur = 0x00219CFF;
int rouge = (couleur >> 16) & 0xFF;
int vert = (couleur >> 8) & 0xFF;
int bleu = couleur & 0xFF;

bleu = bleu * z / 9;

return ((rouge << 16) | (vert << 8) | bleu);
}

void	ft_trans_to_isometric(t_pt pt, int angle)
{
	pt.x = pt.x - pt.z * cos(angle);
	pt.y = pt.y - pt.z * cos(angle);
	printf("x in fun %d", pt.x );
}