#include "../includes/fdf.h"

void plot_pixel(t_fdf *data, int x, int y)
{
	ft_printf("plot_pixel %d + %d  y %d \n ",x,y, x + y * WIN_W);
    if (x >= 0 && x < x + y * WIN_W)
       data->img->addr[x + y * WIN_W] = 0xFFFFFF;
}

void plot_pixel_H(int *imgaddr, int x, int y)
{
	ft_printf("in LINE  %d ! %d", x, y);
    if (x >= 0 && x < WIN_H)
       imgaddr[x + y * WIN_H] = 0xFFFFFF;
}

void ft_drawline_1(t_fdf *data, int start, int x2, int y2)
{
	float	deltax;
	float	deltay;
	int		xincr;
	int		yincr;

	deltax = abs(x2 - start);
	deltay = abs(y2 - start);
	xincr = guess_incr(deltax);
	yincr = guess_incr(deltay);
    int err = deltax - deltay;
    int x = start;
    int y = start;
    while (1)
    {
        plot_pixel(data, x, y);
        if (x == x2 && y == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -deltay)
        {
            err -= deltay;
            x += xincr;
        }
        if (e2 < deltax)
        {
            err += deltax;
            y += yincr;
        }
    }
}
