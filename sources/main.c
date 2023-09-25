/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:05:44 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/25 17:57:06 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	*data;
	int		fd;

	if (argc != 2 || argc == 1)
	{
		print_err(ERR_ARG, 0);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_err("CANT OPEN MAP", 0);
		exit (1);
	}
	data = ft_init_struct(argv[1]);
	data->zoom = ((WIN_W / data->m_lines + WIN_H / data->m_cols) / 5);
	print_matrix(data);
	render(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_inputs, (void *) data);
	mlx_hook(data->win_ptr, 17, 1L, destroy, (void *) data);
	mlx_loop(data->mlx_ptr);
	destroy(data);
	return (0);
}
