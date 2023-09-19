/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:05:44 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:40 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int argc, char *argv[])
{
	t_fdf	*data;
	
	if (argc != 2 || argc == 1)
	{
		print_err(ERR_ARG,0);
		return(1);
	}
	data = ft_init_struct(argv[1]);
	print_matrix(data);
	my_mlx_pixel_put(data->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img_ptr, 0, 0);
	mlx_hook(data->win_ptr, 2, 1L<<0, handle_inputs, (void *)data);
	mlx_loop(data->mlx_ptr);
	destroy(data);
	return(0);
}
