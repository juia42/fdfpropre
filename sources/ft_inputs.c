/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/25 17:57:35 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	handle_inputs2(int key, t_fdf *data)
{
	if (key == XK_KP_Multiply)
	{
		if (data->is_iso == 1)
			data->is_iso = 0;
		else
			data->is_iso = 1;
	}
	if ((key == XK_KP_Add) || (key == 105))
		data->zoom += 1;
	if ((key == XK_KP_Subtract) || (key == 111))
		data->zoom -= 1;
	if ((key == 112))
		data->profondeur += 1;
	if ((key == 59))
		data->profondeur -= 1;
	if ((key == 107))
		data->angle += 1;
	if ((key == 108))
		data->angle -= 1;
}

int	handle_inputs(int key, t_fdf *data)
{
	if (key == XK_Escape)
	{
		destroy(data);
		return (0);
	}
	if (key == XK_Up)
		data->shift_y -= 10;
	if (key == XK_Down)
		data->shift_y += 10;
	if (key == XK_Left)
		data->shift_x -= 10;
	if (key == XK_Right)
		data->shift_x += 10;
	handle_inputs2(key, data);
	render(data);
	return (0);
}
