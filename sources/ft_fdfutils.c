#include "../includes/fdf.h"

// Prints map matrix for debug purposes
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
	printf("eh c fini les gars\n");
}

int	ft_linelen(char *str) //strlen sans espace, s'arrete a \n ou \0
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
			n++;
		i++;
	}
	return (n);
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
