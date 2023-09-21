/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/21 11:26:09 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_inputs(int key, t_fdf *data)
{
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
	render(data);
	return (0);
}
