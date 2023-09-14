#include "../includes/fdf.h"

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

void	ft_get_map(t_fdf *data, char *mapfile)
{
	int	fd;
	char	*line;
	char	*tmp;
	int i;

	i = 0;
	data->map = malloc(sizeof(char **) * data->m_height + 1);
	data->map[data->m_height] = NULL;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd, 0);
	data->m_width = ft_linelen(line);
	while (line)
	{
		data->map[i] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	close(fd);
}

void	get_height(t_fdf *data, char *mapfile)
{
	int	fd;
	char	*line;

	data->m_height = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd, 0);
	while (line)
	{
		data->m_height++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
}

void	ft_convert_map(t_fdf *data)
{
	int i;
	int j;
	char	**tab;

	i = 0;
	data->z_matrix = malloc(sizeof(t_pt *) * data->m_height);
	while (data->map[i])
	{
		j = 0;
		data->z_matrix[i] = malloc(sizeof(t_pt) * data->m_width);
		while (data->map[i][j])
		{
			tab = ft_split(data->map[i][j], ',');
			data->z_matrix[i][j].z = ft_atoi(tab[0]);
			data->z_matrix[i][j].color = 0;
			if (tab[1])
				data->z_matrix[i][j].color = ft_htoi(tab[1] + 2);
			printf("matrix: %d|%d\n", data->z_matrix[i][j].z, data->z_matrix[i][j].color);
			j++;
		}
		i++;
	}
}

t_fdf	*ft_init_struct(char *mapfile)
{
	t_fdf	*data;
	data = malloc(sizeof(t_fdf));
	get_height(data, mapfile);
	ft_get_map(data, mapfile);
	//faire la verif de map carree avant, risque de sigsegv
	ft_convert_map(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");
	data->image = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	return (data);
}
