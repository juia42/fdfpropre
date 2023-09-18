/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchauvin <hchauvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:01:13 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/18 17:23:35 by hchauvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	handle_inputs(int key, t_fdf *data)
{
//	ft_printf("%d\n", key);
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
	if (key == XK_KP_Add)
		data->zoom += 5;
	if (key == XK_KP_Subtract)
		data->zoom -= 5;
	render(data);
	return (0);
}
