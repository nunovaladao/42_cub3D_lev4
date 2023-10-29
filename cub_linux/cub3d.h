/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:06:52 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/27 22:52:16 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# include <math.h>
# include <sys/time.h>

# define mapWidth 24
# define mapHeight 24


# define texWidth 64
# define texHeight 64
# define screenWidth 800
# define screenHeight 600

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct	s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
	struct s_data *data;
}				t_mlx;

typedef struct	s_data
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	double moveSpeed;
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;
	t_mlx *mlx;
	struct s_map *map;
}				t_data;


typedef struct	s_map
{
	char **worldMap; // Matriz para armazenar o mapa
   /*  int mapWidth;
	int mapHeight; */
	double wallX;
	char *map_file;
	int fd;
	char *line;
	int nr_rows;
	t_data *data;
}				t_map;

// Mlx
void	mlx_exit(t_mlx *m);
int	hook_events(t_mlx *m);
void open_window(t_mlx *m);
int keyboard_hook(int keycode, t_mlx *m);

// Init
void init_all(t_mlx *m, t_data *data, t_map *map);

// Parser
int		check_file(char *file);
int    check_args(int ac, char **av);
int check_file_extension(char *file_name);

// Map
void check_map(t_map *map);

// Draw
void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color);
void background(t_mlx *m);

// Moves
void move_forward(t_mlx *m);
void move_backward(t_mlx *m);
void move_left(t_mlx *m);
void move_right(t_mlx *m);
void rotate_left(t_mlx *m);
void rotate_right(t_mlx *m);

# endif