/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/19 13:45:40 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_inputs(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	printf("ave %f\n", data->zoom);
	if (data == NULL)
		print_err("PTR TO STRUCT NULL", 0);
	if (key == XK_Escape)
		destroy(data);
	if (key == XK_Up)
		data->shift_y -= 10;
	if (key == XK_Down)
		data->shift_y += 10;
	if (key == XK_Left)
		data->shift_x -= 10;
	if (key == XK_Right)
		data->shift_x += 10;
	if ((key == XK_KP_Add) || (key == 105))
		data->zoom += 1;
	if ((key == XK_KP_Subtract) || (key == 111))
		data->zoom -= 1;
	
	
	printf("apre %f\n", data->zoom);
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	ft_draw_map(data);
	return (0);
}
