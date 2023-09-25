#include "../includes/fdf.h"

void	print_matrix(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->m_lines)
	{
		j = 0;
		printf("%d", data->z_matrix[i][j++].z);
		while (j < data->m_cols)
		{
			printf("% 3d", data->z_matrix[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	ft_linelen(char *str)
{
	int	i;
	int	n;
	int	in_color;

	i = 0;
	n = 0;
	in_color = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ',')
			in_color = 1;
		else if (str[i] != ' ')
		{
			if (!in_color)
				n++;
			if (in_color && str[i + 1] == ' ')
			{
				i++;
				in_color = 0;
			}
		}
		i++;
	}
	return (n);
}

void	free_zmatrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->m_lines)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}

void	free_map_data(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			free(data->map[i][j]);
			data->map[i][j] = NULL;
			j++;
		}
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}

int	destroy(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free_map_data(data);
	free_zmatrix(data);
	free(data->mlx_ptr);
	free(data->img);
	free(data->ptcenter);
	free(data);
	data = NULL;
	exit (0);
	return (0);
}
