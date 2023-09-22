/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchauvin <hchauvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/22 08:53:49 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_inputs(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (data == NULL)
		print_err("PTR TO STRUCT NULL", 0);
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
	if ((key == XK_KP_Add) || (key == 105))
		data->zoom += 1;
	if ((key == XK_KP_Subtract) || (key == 111))
		data->zoom -= 1;
	if ((key == 112))	// p
		data->profondeur += 1;
	if ((key == 59))	// ;
		data->profondeur -= 1;
	if ((key == 107))	// k
		data->angle += 1;
	if ((key == 108))	// l
		data->angle -= 1;
	render(data);
	return (0);
}
