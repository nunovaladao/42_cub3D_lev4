/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:06:52 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/24 11:35:03 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# include <math.h>

# define mapWidth 24
# define mapHeight 24
# define screenWidth 640
# define screenHeight 480

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct	s_data {

	
	
}				t_data;

typedef struct	s_mlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
	struct s_data *data;
}				t_mlx;

typedef struct	s_map {
	double x;
	double y;
	char *wall;
	int		img_width;
	int		img_height;
	int **map; // Matriz para armazenar o mapa
    int map_width;
    int map_height;
    int tile_size;
}				t_map;

void	mlx_exit(t_data *data);
int	hook_events(t_data *data);
void open_window(t_data *data);
void init_mlx(t_data *data);

// Parser
int		check_file(char *file);
int    check_args(int ac, char **av);
int check_file_extension(char *file_name);


# endif