/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:18:10 by hchauvin          #+#    #+#             */
/*   Updated: 2023/09/19 17:13:50 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define    ERR_ARG "Erreur : nombre d'arguments incorrect ! usage : ./fdf <mapfile>.fdf"
# define    ERR_FILE "Erreur : fichier incorrect ! usage : ./fdf <mapfile>.fdf"
# define    WIN_H   1080
# define    WIN_W   1920
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../includes/libft/libft.h"
# include "../includes/mlx.h"
# include "./minilibx_linux/mlx_int.h"

typedef struct	s_pt	t_pt;
typedef struct	s_image	t_image;

typedef struct s_fdf
{
	char	***map;
    int		m_cols;
    int		m_lines;
    float	zoom;
    int		shift_x;
    int		shift_y;
    void    *mlx_ptr;
    void    *win_ptr;
	t_image	*img;
    t_pt	**z_matrix;
}   t_fdf;

typedef struct s_pt
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pt;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

// Data
int		ft_linelen(char *str);
t_fdf   *ft_init_struct(char *map_file_name);	// Initializes data structure.
t_image	*ft_init_img(t_fdf *data);
void	ft_get_map(t_fdf *data, char *mapfile);	// Get map informations
void	ft_convert_map(t_fdf *data);			// Adds z and color detail for each point.
int		handle_inputs(int key, t_fdf *data);	// Grabs input
int		destroy(t_fdf *data);
//line 

void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	ft_draw_map(t_fdf *data);
int		ft_calcul_color(int z);
// Render
// Debug
void	print_matrix(t_fdf *data);				// Prints map in terminal.

#endif
