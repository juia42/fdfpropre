#include "../includes/fdf.h"

void	ft_get_map(t_fdf *data, char *mapfile)
{
	int		fd;
	char	*line;
	char	*tmpline;
	int		i;
	char	**tab;

	i = 0;
	data->map = malloc(sizeof(char **) * (data->m_lines + 1));
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd, 0);
	tmpline = line;
	tab = ft_split(tmpline, ' ');
	data->m_cols = ft_arraylen(tab);
	free_array(tab);
	while (line)
	{
		data->map[i] = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	data->map[i] = NULL;
	ft_printf("%d\n", data->m_cols);
	close(fd);
}

void	get_height(t_fdf *data, char *mapfile)
{
	int		fd;
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
	int		i;
	int		j;
	char	**tab;

	i = 0;
	data->z_matrix = malloc(sizeof(t_pt *) * data->m_lines);
	while (i < data->m_lines)
	{
		j = 0;
		data->z_matrix[i] = malloc(sizeof(t_pt) * data->m_cols);
		while (j < data->m_cols)
		{
			tab = ft_split(data->map[i][j], ',');
			data->z_matrix[i][j].z = ft_atoi(tab[0]);
			data->z_matrix[i][j].color = 0x00B0F2B6;
			data->z_matrix[i][j].x = j;
			data->z_matrix[i][j].y = i;
			if (tab[1])
				data->z_matrix[i][j].color = ft_htoi(tab[1] + 2);
			j++;
			free_array(tab);
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
	ft_convert_map(data);
	data->zoom = 6;
	data->angle = 30;
	data->is_iso = 1;
	data->shift_x = 100;
	data->shift_y = 100;
	data->profondeur = 1;
	data->ptcenter = malloc(sizeof(t_pt));
	data->ptcenter->x = data->m_cols / 2;
	data->ptcenter->y = data->m_lines / 2;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");
	data->img = ft_init_img(data);
	return (data);
}

t_image	*ft_init_img(t_fdf *data)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->img_ptr = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_len), &(img->endian));
	return (img);
}
