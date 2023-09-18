/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchauvin <hchauvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:38:15 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/18 17:39:06 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define MAX1(a, b) (a > b ? a : b)

float	mod(float i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

int	guess_incr(float delta)
{
	if (delta >= 0)
		return (1);
	return (-1);
}
/*
void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int	max;
//	int	z;
//	int	z1;

//	z = data->z_matrix[(int)y][(int)x];
//	z1 = data->z_matrix[(int)y1][(int)x1];

	// Zoom

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	// Color
	//data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	// Isometric
//	isometric(&x, &y, z, data);
//	isometric(&x1, &y1, z1, data);
	// Shift
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}
*/
void	ligne_bresen(t_fdf *data, t_pt *origine, t_pt *arrivee)
{
	float	deltax;
	float	deltay;
	//float	slope;
	float	error;
	float	nexterr;
	int		xincr;
	int		yincr;
	
	deltax = abs(arrivee->x - origine->x);
	deltay = abs(arrivee->y - origine->y);
	xincr = guess_incr(deltax);
	yincr = guess_incr(deltay);
	//slope = deltax / deltay;
	error = 0;
	while (origine->x != arrivee->x && origine->y != arrivee->y)
	{
		img_pix_put(data->img, (int)origine->x, (int)origine->y, origine->color);
		if (origine->x == arrivee->x && origine->y == arrivee->y)
		{
			ft_printf("i cut the loop\n");
			break;
		}
		nexterr = error * 2;
		if (nexterr >= -deltay)
		{
			error -= deltay;
			origine->x += xincr;
		}
		else if (nexterr < deltax)
		{
			error += deltax;
			origine->y += yincr;
		}
		//img_pix_put(data->img, (int)origine->x, (int)origine->y, origine->color);
	}
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int	i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
