#include "../includes/fdf.h"

// Prints map matrix for debug purposes
void	print_matrix(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->m_height)
	{
		j = 0;
		ft_printf("%d", data->z_matrix[i][j++]);
		while (j < data->m_width)
		{
			printf("% 3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// Count words to see number of value per line.
int	ft_count_words(char *str)
{
	int i;
	int	is_word;
	int	cnt;

	cnt = 0;
	is_word = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			cnt++;
		}
	}
	return (cnt);
}

// free le contenu de la structure
void	free_all_data(t_fdf *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]); 
	//free le reste de la structure
}

// destruit tout ce qui est lie a la mlx et free la structure
int	destroy(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free_all_data(data);
	free(data->mlx_ptr);
	free(data);
	exit (0);
	return (0);
}
