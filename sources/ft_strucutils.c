#include "../includes/fdf.h"

void	ft_get_map(t_fdf *data, char *mapfile)
{
	int	fd;
	char	*line;
	int i;

	i = 0;
	data->map = malloc(sizeof(char **) * data->m_lines + 1);
	data->map[data->m_lines] = NULL;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd, 0);
	data->m_cols = ft_linelen(line);
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

	data->m_lines = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd, 0);
	while (line)
	{
		data->m_lines++;
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
	data->z_matrix = malloc(sizeof(t_pt *) * data->m_lines);
	while (data->map[i])
	{
		j = 0;
		data->z_matrix[i] = malloc(sizeof(t_pt) * data->m_cols);
		while (data->map[i][j])
		{
			tab = ft_split(data->map[i][j], ',');
			data->z_matrix[i][j].z = ft_atoi(tab[0]);
			data->z_matrix[i][j].color = 0;
			data->z_matrix[i][j].x = j;
			data->z_matrix[i][j].y = i;
			if (tab[1])
				data->z_matrix[i][j].color = ft_htoi(tab[1] + 2);
			//printf("matrix: %d|%d\n", data->z_matrix[i][j].z, data->z_matrix[i][j].color);
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
	data->zoom = 0;
	data->shift_x = 150;
	data->shift_y = 150;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");
	data->img = ft_init_img(data);
	return (data);
}

t_image	*ft_init_img(t_fdf *data)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp), &(image->line_len), &(image->endian));
	return (image);
}